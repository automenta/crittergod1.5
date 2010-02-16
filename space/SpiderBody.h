/* 
 * File:   SpiderBody.h
 * Author: seh
 *
 * Created on February 15, 2010, 9:18 PM
 */

#ifndef _SPIDERBODY_H
#define	_SPIDERBODY_H

#include <math.h>

#include "DefaultSpace.h"
#include "AbstractBody.h"

#include "../neural/Brain.h"
#include "../bio/NPosition.h"
#include "../bio/SixDoFMotor.h"
#include "../bio/SineSound.h"

#define GPS_HARMONICS 4
#define SPACE_FREQ  0.1 //lower requires brains to be more sensitive but gives more dynamic range in the space

class SpiderBody : public AbstractBody {
    Brain* brain;

    float m_fMuscleStrength;

    int NUM_LEGS, PART_COUNT, JOINT_COUNT;

    btVector3 positionOffset;
    vector<SixDoFMotor*> jointControllers;

    NPosition* posCenter;
    SineSound* voice;

public:

    SpiderBody(int numLegs, const btVector3& _positionOffset) {
        NUM_LEGS = numLegs;

        PART_COUNT = 2 * NUM_LEGS + 1;
        JOINT_COUNT = PART_COUNT - 1;
        positionOffset = _positionOffset;
    }

    virtual void init() {
        shapes.reserve(PART_COUNT);
        bodies.reserve(PART_COUNT);
        joints.reserve(JOINT_COUNT);

        btVector3 vUp(0, 1, 0);
        m_fMuscleStrength = 0.9f;

        //
        // Setup geometry
        //
        float fBodySize = 0.25f;
        //        float fLegLength = 0.45f;
        //        float fForeLegLength = 0.85f;
        float fHeight = 0.5;
        float fLegLength = 0.6f;
        float fForeLegLength = 0.5f;

        shapes.push_back(new btCapsuleShape(btScalar(fBodySize), btScalar(0.10)));
        unsigned i;
        for (i = 0; i < NUM_LEGS; i++) {
            shapes.push_back(new btCapsuleShape(btScalar(0.10), btScalar(fLegLength)));
        }
        for (i = 0; i < NUM_LEGS; i++) {
            shapes.push_back(new btCapsuleShape(btScalar(0.08), btScalar(fForeLegLength)));
        }

        int numNeurons = 1024;
        int minSynapses = 1;
        int maxSynapses = 6;


        brain = new Brain(numNeurons, minSynapses, maxSynapses, 0.5);

        posCenter = new NPosition(brain, 1);


        //
        // Setup rigid bodies
        //
        btTransform offset;
        offset.setIdentity();
        offset.setOrigin(positionOffset);

        // root
        btVector3 vRoot = btVector3(btScalar(0.), btScalar(fHeight), btScalar(0.));
        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(vRoot);

        bodies.push_back(localCreateRigidBody(btScalar(1.), offset*transform, shapes[0]));

        // legs
        for (i = 0; i < NUM_LEGS; i++) {
            float fAngle = 2 * M_PI * i / NUM_LEGS;
            float fSin = sin(fAngle);
            float fCos = cos(fAngle);

            transform.setIdentity();
            btVector3 vBoneOrigin = btVector3(btScalar(fCos * (fBodySize + 0.5 * fLegLength)), btScalar(fHeight), btScalar(fSin * (fBodySize + 0.5 * fLegLength)));
            transform.setOrigin(vBoneOrigin);

            // thigh
            btVector3 vToBone = (vBoneOrigin - vRoot).normalize();
            btVector3 vAxis = vToBone.cross(vUp);
            transform.setRotation(btQuaternion(vAxis, M_PI_2));
            bodies[1 + i] = localCreateRigidBody(btScalar(1.), offset*transform, shapes[1 + i]);

            // shin
            transform.setIdentity();
            transform.setOrigin(btVector3(btScalar(fCos * (fBodySize + fLegLength)), btScalar(fHeight - 0.5 * fForeLegLength), btScalar(fSin * (fBodySize + fLegLength))));
            bodies[1 + i + NUM_LEGS] = localCreateRigidBody(btScalar(1.), offset*transform, shapes[1 + i + NUM_LEGS]);
        }

        // Setup some damping on the m_bodies
        for (i = 0; i < PART_COUNT; ++i) {
            bodies[i]->setDamping(0.05, 0.85);
            bodies[i]->setDeactivationTime(0.8);
            bodies[i]->setSleepingThresholds(0.5f, 0.5f);
            //m_bodies[i]->setSleepingThresholds(1.6, 2.5);
        }


        //
        // Setup the constraints
        //
        btHingeConstraint* hingeC;
        //btConeTwistConstraint* coneC;

        btTransform localA, localB;

        int joint = 0;
        for (unsigned j = 0; j < 2; j++) {
            //j=0: bind leg to center
            //j=1: bind foreleg to leg

            for (i = 0; i < NUM_LEGS; i++) {

                double la, lb;

                btGeneric6DofConstraint* c;

                localA.setIdentity();
                localB.setIdentity();
                if (j % 2 == 0) {
                    double headroomFactor = 1.5;
                    la = fBodySize;
                    lb = fLegLength;

                    float fAngle = 2 * M_PI * i / NUM_LEGS;
                    float fSin = sin(fAngle);
                    float fCos = cos(fAngle);

                    localA.getBasis().setEulerZYX(0, -fAngle, 0);
                    localA.setOrigin(btVector3(btScalar(fCos * fBodySize), btScalar(0.), btScalar(fSin * fBodySize)));
                    localB = bodies[1 + i]->getWorldTransform().inverse() * bodies[0]->getWorldTransform() * localA;

                    c = new btGeneric6DofConstraint(*bodies[0], *bodies[1 + i], localA, localB, false);
                    c->setAngularLowerLimit(btVector3(-M_PI_8, -M_PI_8, -M_PI_8));
                    c->setAngularUpperLimit(btVector3(M_PI_8, M_PI_8, M_PI_8));
                } else {
                    double headroomFactor = 1.3;
                    la = fLegLength;
                    lb = fForeLegLength;

                    localA.setOrigin(btVector3(0, -(la / 2) * headroomFactor, 0));
                    localB.setOrigin(btVector3(0, (lb / 2) * headroomFactor, 0));

                    c = new btGeneric6DofConstraint(*bodies[1 + i], *bodies[1 + NUM_LEGS + i], localA, localB, false);
                    c->setAngularLowerLimit(btVector3(-M_PI_4, -M_PI_4, -M_PI_4));
                    c->setAngularUpperLimit(btVector3(M_PI_4, M_PI_4, M_PI_4));
                }

                joints[joint++] = c;
                dyn->addConstraint(c);

                SixDoFMotor* sm = new SixDoFMotor(brain, c);
                jointControllers.push_back(sm);

            }
        }



        //		for ( i=0; i<NUM_LEGS; i++)
        //		{
        //			float fAngle = 2 * M_PI * i / NUM_LEGS;
        //			float fSin = sin(fAngle);
        //			float fCos = cos(fAngle);
        //
        //			// hip joints
        //			localA.setIdentity(); localB.setIdentity();
        //			localA.getBasis().setEulerZYX(0,-fAngle,0);	localA.setOrigin(btVector3(btScalar(fCos*fBodySize), btScalar(0.), btScalar(fSin*fBodySize)));
        //			localB = bodies[1+2*i]->getWorldTransform().inverse() * bodies[0]->getWorldTransform() * localA;
        //			hingeC = new btHingeConstraint(*bodies[0], *bodies[1+2*i], localA, localB);
        //			hingeC->setLimit(btScalar(-0.75 * M_PI_4), btScalar(M_PI_8));
        //			//hingeC->setLimit(btScalar(-0.1), btScalar(0.1));
        //			joints[2*i] = hingeC;
        //			dyn->addConstraint(joints[2*i], true);
        //
        //			// knee joints
        //			localA.setIdentity(); localB.setIdentity(); localC.setIdentity();
        //			localA.getBasis().setEulerZYX(0,-fAngle,0);	localA.setOrigin(btVector3(btScalar(fCos*(fBodySize+fLegLength)), btScalar(0.), btScalar(fSin*(fBodySize+fLegLength))));
        //			localB = bodies[1+2*i]->getWorldTransform().inverse() * bodies[0]->getWorldTransform() * localA;
        //			localC = bodies[2+2*i]->getWorldTransform().inverse() * bodies[0]->getWorldTransform() * localA;
        //			hingeC = new btHingeConstraint(*bodies[1+2*i], *bodies[2+2*i], localB, localC);
        //			//hingeC->setLimit(btScalar(-0.01), btScalar(0.01));
        //			hingeC->setLimit(btScalar(-M_PI_8), btScalar(0.2));
        //			joints[1+2*i] = hingeC;
        //			dyn->addConstraint(joints[1+2*i], true);
        //		}

        voice = new SineSound(brain, space->audio, 128);

        brain->init();
        brain->printSummary();
    }

    virtual btVector3 getColor(btCollisionShape* shape) {
        float i = (float) (indexOfShape(shape) % 2);
        return btVector3(0.8 + i * 0.5, 0.2 + i * 0.2, 0.8);
    }

    virtual void process(btScalar dt) {
        posCenter->set(bodies[0]->getCenterOfMassPosition(), 0.1);
        posCenter->process(dt);

        //process brain
        brain->forward(dt);

        for (unsigned j = 0; j < jointControllers.size(); j++)
            jointControllers[j]->process(dt);

        voice->process(dt);
        
        //read outputs
        //		for (int i=0; i<2*NUM_LEGS; i++) {
        //			btHingeConstraint* hingeC = static_cast<btHingeConstraint*>(joints[i]);
        //			btScalar fCurAngle      = hingeC->getHingeAngle();
        //
        //			//btScalar fTargetPercent = getLegTargetPercent(i, r); //(int(m_Time / 1000) % int(m_fCyclePeriod)) / m_fCyclePeriod;
        //			btScalar fTargetAngle   = -1.0 + (getLegTargetAngle(i/2, i%2))*M_PI*4.0; //0.5 * (1 + sin(2 * M_PI * fTargetPercent));
        //
        //			btScalar fTargetLimitAngle = hingeC->getLowerLimit() + fTargetAngle * (hingeC->getUpperLimit() - hingeC->getLowerLimit());
        //			btScalar fAngleError  = fTargetLimitAngle - fCurAngle;
        //			btScalar fDesiredAngularVel = 1000000.f * fAngleError/dt*1000000.;
        //			hingeC->enableAngularMotor(true, fDesiredAngularVel, m_fMuscleStrength);
        //		}


    }

    btScalar getLegTargetAngle(int leg, bool hipOrKnee) {
        return brain->outs[leg * 2 + hipOrKnee]->getOutput();
    }

    virtual ~SpiderBody() {
        int i;

        // Remove all constraints
        for (i = 0; i < JOINT_COUNT; ++i) {
            dyn->removeConstraint(joints[i]);
            delete joints[i];
            joints[i] = 0;
        }

        // Remove all bodies and shapes
        for (i = 0; i < PART_COUNT; ++i) {
            dyn->removeRigidBody(bodies[i]);

            delete bodies[i]->getMotionState();

            delete bodies[i];
            bodies[i] = 0;
            delete shapes[i];
            shapes[i] = 0;
        }
    }

};


#endif	/* _SPIDERBODY_H */

