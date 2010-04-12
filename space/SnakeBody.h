/*
 * CritterBody.h
 *
 *  Created on: Jan 26, 2010
 *      Author: seh
 */

#ifndef CRITTERBODY_H_
#define CRITTERBODY_H_

#include <math.h>

#include "DefaultSpace.h"
#include "AbstractBody.h"
#include "../neural/Brain.h"

#include "../bio/SixDoFMotor.h"
#include "../bio/NPosition.h"
#include "../bio/NColor.h"
#include "../bio/SineSound.h"
#include "../bio/Retina.h"

#define GPS_HARMONICS 4
#define SPACE_FREQ  0.1 //lower requires brains to be more sensitive but gives more dynamic range in the space

class SnakeBody : public AbstractBody {

    float m_fMuscleStrength;

    unsigned segments;
    btVector3 positionOffset;

    vector<SixDoFMotor*> jointControllers;

    NPosition *posHead, *posTail;
    NColor *bodyColorA, *bodyColorB;
    vector<SineSound*> voices;

public:
    Brain* brain;
    Retina* eyeRetina;

    SnakeBody(const btVector3& _positionOffset, unsigned _parts) {
        positionOffset = _positionOffset;
        segments = _parts;
    }

    virtual void init() {

        btVector3 vUp(0, 1, 0);
        m_fMuscleStrength = 0.5f;

        int numEyes = 1;

        shapes.reserve(segments + numEyes);
        bodies.reserve(segments + numEyes);
        joints.reserve(segments - 1);

        //
        // Setup geometry
        //
        float fBodySize = 0.15f;
        float fPartLength = 0.45f;
        unsigned i;
        for (i = 0; i < segments; i++) {
            shapes.push_back(new btCapsuleShape(btScalar(fBodySize), btScalar(fPartLength)));
        }
        shapes.push_back(new btBoxShape(btVector3(0.25, 0.1, 0.1))); //eye

        int numNeurons = 16384;
        int minSynapses = 1;
        int maxSynapses = 4;


        brain = new Brain(numNeurons, minSynapses, maxSynapses, 0.5);


        //
        // Setup rigid bodies
        //
        float fHeight = 0.5;
        btTransform offset;
        offset.setIdentity();
        offset.setOrigin(positionOffset);

        // root
        btVector3 vRoot = btVector3(btScalar(0.), btScalar(fHeight), btScalar(0.));
        btTransform transform;
        transform.setIdentity();
        transform.setOrigin(vRoot);
        //m_bodies[0] = localCreateRigidBody(btScalar(1.), offset * transform,m_shapes[0]);

        for (i = 0; i < segments; i++) {
            float fAngle = 2 * M_PI * i / segments;
            float fSin = sin(fAngle);
            float fCos = cos(fAngle);

            transform.setIdentity();
            transform.setOrigin(btVector3(0, i, 0));
            //			btVector3 vBoneOrigin = btVector3(btScalar(fCos * (fBodySize + 0.5
            //					* fPartLength)), btScalar(fHeight), btScalar(fSin
            //					* (fBodySize + 0.5 * fPartLength)));
            //			transform.setOrigin(vBoneOrigin);
            //
            //			transform.setIdentity();
            //			transform.setOrigin(btVector3(btScalar(fCos * (fBodySize
            //					+ fPartLength)), btScalar(fHeight - 0.5 * fPartLength),
            //					btScalar(fSin * (fBodySize + fPartLength))));
            bodies[i] = localCreateRigidBody(btScalar(1.), offset * transform, shapes[i]);

            //			for (unsigned j = 0; j < legParts; j++) {
            //				if (j == 0) {
            //					// thigh
            //					btVector3 vToBone = (vBoneOrigin - vRoot).normalize();
            //					btVector3 vAxis = vToBone.cross(vUp);
            //					transform.setRotation(btQuaternion(vAxis, M_PI_2));
            //					m_bodies[1 + j + legParts * i] = localCreateRigidBody(
            //							btScalar(1.), offset * transform, m_shapes[1 + 2
            //									* i]);
            //				} else if (j == 1) {
            //					// shin
            //					transform.setIdentity();
            //					transform.setOrigin(btVector3(btScalar(fCos * (fBodySize
            //							+ fLegLength)), btScalar(fHeight - 0.5
            //							* fForeLegLength), btScalar(fSin * (fBodySize
            //							+ fLegLength))));
            //					m_bodies[1 + j + legParts * i] = localCreateRigidBody(
            //							btScalar(1.), offset * transform, m_shapes[2 + 2
            //									* i]);
            //				}
            //			}

        }
        bodies[i] = localCreateRigidBody(btScalar(1.), offset * transform, shapes[i]);

        // Setup some damping on the m_bodies
        for (i = 0; i < bodies.size(); ++i) {
            bodies[i]->setDamping(0.05, 0.85);
            bodies[i]->setDeactivationTime(0.8);
            //m_bodies[i]->setSleepingThresholds(1.6, 2.5);
            bodies[i]->setSleepingThresholds(0.5f, 0.5f);
        }

        //
        // Setup the constraints
        //
        //btGeneric6DoFConstraint* hingeC;
        //btConeTwistConstraint* coneC;

        btTransform localA, localB;

        unsigned joint = 0;
        for (i = 0; i < segments - 1; i++) {
            float fAngle = 2 * M_PI * i / segments;
            float fSin = sin(fAngle);
            float fCos = cos(fAngle);

            //						localA.setIdentity(); localB.setIdentity();
            //						localA.getBasis().setEulerZYX(0,-fAngle,0);
            //						localA.setOrigin(btVector3(btScalar(fCos*fBodySize), btScalar(0.), btScalar(fSin*fBodySize)));
            //						localB = m_bodies[i]->getWorldTransform().inverse() * m_bodies[i+1]->getWorldTransform() * localA;
            //						hingeC->setLimit(btScalar(0), btScalar(0.15));

            double headroomFactor = 1.5;

            localA.setIdentity();
            localA.setOrigin(btVector3(0, (fPartLength / 2) * headroomFactor, 0));
            localB.setIdentity();
            localB.setOrigin(btVector3(0, -(fPartLength / 2) * headroomFactor, 0));

            btGeneric6DofConstraint* c = new btGeneric6DofConstraint(
                    *bodies[i], *bodies[i + 1], localA, localB, false);

            c->setAngularLowerLimit(btVector3(-M_PI_4, -M_PI_4, -M_PI_4));
            c->setAngularUpperLimit(btVector3(M_PI_4, M_PI_4, M_PI_4));

            joints[joint++] = c;
            dyn->addConstraint(c);

            SixDoFMotor* sm = new SixDoFMotor(brain, c, 0.001, M_PI_4, 0.1, 0.1);
            jointControllers.push_back(sm);

            //			// hip joints
            //			localA.setIdentity(); localB.setIdentity();
            //			localA.getBasis().setEulerZYX(0,-fAngle,0);	localA.setOrigin(btVector3(btScalar(fCos*fBodySize), btScalar(0.), btScalar(fSin*fBodySize)));
            //			localB = m_bodies[1+2*i]->getWorldTransform().inverse() * m_bodies[0]->getWorldTransform() * localA;
            //			hingeC = new btGeneric6DoFConstraint(*m_bodies[0], *m_bodies[1+2*i], localA, localB);
            //			hingeC->setLimit(btScalar(-0.75 * M_PI_4), btScalar(M_PI_8));
            //			//hingeC->setLimit(btScalar(0), btScalar(M_PI));
            //			//hingeC->setLimit(btScalar(-0.1), btScalar(0.1));
            //			m_joints[2*i] = hingeC;
            //			m_ownerWorld->addConstraint(m_joints[2*i], true);
            //
            //			// knee joints
            //			localA.setIdentity(); localB.setIdentity(); localC.setIdentity();
            //			localA.getBasis().setEulerZYX(0,-fAngle,0);	localA.setOrigin(btVector3(btScalar(fCos*(fBodySize+fLegLength)), btScalar(0.), btScalar(fSin*(fBodySize+fLegLength))));
            //			localB = m_bodies[1+2*i]->getWorldTransform().inverse() * m_bodies[0]->getWorldTransform() * localA;
            //			localC = m_bodies[2+2*i]->getWorldTransform().inverse() * m_bodies[0]->getWorldTransform() * localA;
            //			hingeC = new btGeneric6DoFConstraint(*m_bodies[1+2*i], *m_bodies[2+2*i], localB, localC);
            //			hingeC->setLimit(btScalar(0), btScalar(0.15));
            //			//hingeC->setLimit(btScalar(0), btScalar(M_PI));
            //			m_joints[1+2*i] = hingeC;
            //			m_ownerWorld->addConstraint(m_joints[1+2*i], true);
        }

        //Eye
        localA.setIdentity();
        localA.setOrigin(btVector3(0, -0.25, 0));
        localB.setIdentity();
        localB.setOrigin(btVector3(0, 0.25, 0));
        btGeneric6DofConstraint* cp = new btGeneric6DofConstraint(*bodies[0], *bodies[i + 1], localA, localB, false);
        
        cp->setAngularLowerLimit(btVector3(0, 0, 0));
        cp->setAngularUpperLimit(btVector3(0, 0, 0));
        joints[joint++] = cp;
        dyn->addConstraint(cp);

        eyeRetina = new Retina(brain, space->dynamicsWorld, bodies[i+1], 32, 24, 0.25, 50.0);

        posHead = new NPosition(brain, 1);
        posTail = new NPosition(brain, 1);

        bodyColorA = new NColor(brain);
        bodyColorB = new NColor(brain);

        //musical scale
        voices.push_back( new SineSound(brain, space->audio, 396) );
        voices.push_back( new SineSound(brain, space->audio, 417) );
        voices.push_back( new SineSound(brain, space->audio, 528) );
        voices.push_back( new SineSound(brain, space->audio, 639) );
        voices.push_back( new SineSound(brain, space->audio, 741) );
        voices.push_back( new SineSound(brain, space->audio, 852) );

        brain->init();
        brain->printSummary();

    }

    //sinusoidal gps filter

    float sinGPS(int harmonic, float x) {
        return sin(x * SPACE_FREQ * pow(2, harmonic)) / ((float) harmonic);
    }

    virtual btVector3 getColor(btCollisionShape* shape) {
        int i = indexOfShape(shape) % 2;
        if (i == 0) {
            return bodyColorA->getColor();
        } else {
            return bodyColorB->getColor();
        }
        //return btVector3(0.3+i*0.5, 0.8+ i*0.2, 0.4);
    }

    virtual void process(btScalar dt) {
        posHead->setSin(bodies[0]->getCenterOfMassPosition(), 0.1);
        posTail->setSin(bodies[segments - 1]->getCenterOfMassPosition(), 0.1);
        posHead->process(dt);
        posTail->process(dt);

        eyeRetina->process(dt);
        
        //process brain
        brain->forward(dt);

        for (unsigned j = 0; j < jointControllers.size(); j++)
            jointControllers[j]->process(dt);

        bodyColorA->process(dt);
        bodyColorB->process(dt);

        for (unsigned v = 0; v< voices.size(); v++)
            voices[v]->process(dt);
    }

    btScalar getLegTargetAngle(int part) {
        return brain->outs[part]->getOutput();
    }

    virtual ~SnakeBody() {
        int i;

        // Remove all constraints
        for (i = 0; i < segments - 1; ++i) {
            dyn->removeConstraint(joints[i]);
            delete joints[i];
            joints[i] = 0;
        }

        // Remove all bodies and shapes
        for (i = 0; i < segments; ++i) {
            dyn->removeRigidBody(bodies[i]);

            delete bodies[i]->getMotionState();

            delete bodies[i];
            bodies[i] = 0;
            delete shapes[i];
            shapes[i] = 0;
        }
    }

    //	btTypedConstraint** GetJoints() {
    //		return &m_joints[0];
    //	}

};




#endif /* CRITTERBODY_H_ */
