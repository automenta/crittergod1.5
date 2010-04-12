/*
 * RagDoll.h
 *
 *  Created on: Feb 14, 2010
 *      Author: seh
 */

#ifndef HUMANOID_H_
#define HUMANOID_H_

#include "AbstractBody.h"

#include "../bio/Retina.h"
#include "../bio/SixDoFMotor.h"
#include "../neural/Brain.h"

class Humanoid : public AbstractBody {
    float m_fMuscleStrength;

    btVector3 positionOffset;

    SixDoFMotor *neckMotor;
    SixDoFMotor *leftShoulderMotor, *rightShoulderMotor;
    SixDoFMotor *leftElbowMotor, *rightElbowMotor;

public:
    Retina* eyeRetina;
    Retina* lhRetina;
    Retina* rhRetina;
    Brain* brain;

    Humanoid(const btVector3& _positionOffset) {
        positionOffset = _positionOffset;
    }

    virtual void init() {
        btVector3 vUp(0, 1, 0);
        m_fMuscleStrength = 0.5f;


        int numNeurons = 16384;
        int minSynapses = 1;
        int maxSynapses = 8;

        brain = new Brain(numNeurons, minSynapses, maxSynapses, 0.5);

        //
        // Setup geometry
        //
        btTransform t;
        t.setIdentity();

        btRigidBody* torso = createRigidShape(62.0, t, new btBoxShape(btVector3(0.5, 1.0, 1.0)));

        t.setIdentity();
        t.setOrigin(positionOffset);
        btRigidBody* head = createRigidShape(3.0, t, new btBoxShape(btVector3(0.3, 0.3, 0.4)));


        btRigidBody* eye = createRigidShape(1.0, t, new btBoxShape(btVector3(0.05, 0.2, 0.2)));
        {
            //eye joint: Eye to Head

            btTransform localA, localB;

            localA.setIdentity();
            localA.setOrigin(btVector3(-0.2, 0, 0));
            localB.setIdentity();
            localB.setOrigin(btVector3(0.2, 0, 0));

            btGeneric6DofConstraint* c = new btGeneric6DofConstraint(*eye, *head, localA, localB, false);

            c->setAngularLowerLimit(btVector3(0, 0, 0));
            c->setAngularUpperLimit(btVector3(0, 0, 0));

            createJoint(c);

        }

        eyeRetina = new Retina(brain, space->dynamicsWorld, eye, 32, 24, 0.33, 50.0);

        {
            //neck joint: torso->head

            double neckLength = 1.5;

            btTransform localA, localB;

            localA.setIdentity();
            localA.setOrigin(btVector3(0, (neckLength / 2), 0));
            localB.setIdentity();
            localB.setOrigin(btVector3(0, -(neckLength / 2), 0));

            btGeneric6DofConstraint* c = new btGeneric6DofConstraint(*torso, *head, localA, localB, false);

            float sideToSideTilt = M_PI_8;
            float sideToSideRoll = M_PI_8;
            float forwardTilt = M_PI_8;
            c->setAngularLowerLimit(btVector3(-sideToSideTilt, sideToSideRoll, -forwardTilt));
            c->setAngularUpperLimit(btVector3(sideToSideTilt, sideToSideRoll, forwardTilt));

            createJoint(c);

            neckMotor = new SixDoFMotor(brain, c, 0.001, M_PI_4, 0.1, 0.1);
        }


        {
            float sideToSideTilt = M_PI_8;
            float sideToSideRoll = M_PI_8;
            float forwardTilt = M_PI_8;

            double backArmLength = 0.6;
            double backArmWidth = 0.2;
            double foreArmLength = 0.4;
            double foreArmWidth = 0.15;

            //left arm
            btRigidBody* leftBackArm = createRigidShape(2.0, t, new btBoxShape(btVector3(backArmLength, backArmWidth, backArmWidth)));
            btRigidBody* rightBackArm = createRigidShape(2.0, t, new btBoxShape(btVector3(backArmLength, backArmWidth, backArmWidth)));

            btTransform localA, localB;

            {

                localA.setIdentity();
                localA.setOrigin(btVector3(0, 0, 1.5));
                localB.setIdentity();
                localB.setOrigin(btVector3(-backArmLength / 2.0, 0, backArmWidth / 2.0));

                btGeneric6DofConstraint* c = new btGeneric6DofConstraint(*torso, *leftBackArm, localA, localB, false);

                float sideToSideTilt = M_PI_8;
                float sideToSideRoll = M_PI_8;
                float forwardTilt = M_PI_8;
                c->setAngularLowerLimit(btVector3(-sideToSideTilt, sideToSideRoll, -forwardTilt));
                c->setAngularUpperLimit(btVector3(sideToSideTilt, sideToSideRoll, forwardTilt));

                createJoint(c);
                leftShoulderMotor = new SixDoFMotor(brain, c, 0.001, M_PI_4, 0.1, 0.1);
            }
            {

                localA.setIdentity();
                localA.setOrigin(btVector3(0, 0, -1.5));
                localB.setIdentity();
                localB.setOrigin(btVector3(-backArmLength / 2.0, 0, backArmWidth / 2.0));

                btGeneric6DofConstraint* c = new btGeneric6DofConstraint(*torso, *rightBackArm, localA, localB, false);

                c->setAngularLowerLimit(btVector3(-sideToSideTilt, sideToSideRoll, -forwardTilt));
                c->setAngularUpperLimit(btVector3(sideToSideTilt, sideToSideRoll, forwardTilt));

                createJoint(c);
                rightShoulderMotor = new SixDoFMotor(brain, c, 0.001, M_PI_4, 0.1, 0.1);
            }



            //forearm
            btRigidBody* leftForeArm = createRigidShape(1.0, t, new btBoxShape(btVector3(foreArmLength, foreArmWidth, foreArmWidth)));
            btRigidBody* rightForeArm = createRigidShape(1.0, t, new btBoxShape(btVector3(foreArmLength, foreArmWidth, foreArmWidth)));
            {
                localA.setIdentity();
                localA.setOrigin(btVector3(backArmLength, 0, backArmWidth / 2.0));
                localB.setIdentity();
                localB.setOrigin(btVector3(-foreArmLength, 0, foreArmWidth / 2.0));

                btGeneric6DofConstraint* c2 = new btGeneric6DofConstraint(*leftBackArm, *leftForeArm, localA, localB, false);

                c2->setAngularLowerLimit(btVector3(0, -sideToSideTilt, 0));
                c2->setAngularUpperLimit(btVector3(0, sideToSideTilt, 0));

                createJoint(c2);

                leftElbowMotor = new SixDoFMotor(brain, c2, 0.001, M_PI_4, 0.1, 0.1);

                btRigidBody* lhEye = createRigidShape(1.0, t, new btBoxShape(btVector3(0.05, 0.2, 0.2)));
                {
                    //eye joint: Eye to Head

                    btTransform localA, localB;

                    localA.setIdentity();
                    localA.setOrigin(btVector3(foreArmLength, 0, 0));
                    localB.setIdentity();
                    localB.setOrigin(btVector3(-0.2, 0, 0));

                    btGeneric6DofConstraint* c = new btGeneric6DofConstraint(*leftForeArm, *lhEye, localA, localB, false);

                    c->setAngularLowerLimit(btVector3(0, 0, 0));
                    c->setAngularUpperLimit(btVector3(0, 0, 0));

                    createJoint(c);

                }

                lhRetina = new Retina(brain, space->dynamicsWorld, lhEye, 16, 8, 0.25, 50.0);

            }

            {
                localA.setIdentity();
                localA.setOrigin(btVector3(backArmLength, 0, -backArmWidth / 2.0));
                localB.setIdentity();
                localB.setOrigin(btVector3(-foreArmLength, 0, -foreArmWidth / 2.0));

                btGeneric6DofConstraint* c2 = new btGeneric6DofConstraint(*rightBackArm, *rightForeArm, localA, localB, false);

                c2->setAngularLowerLimit(btVector3(0, -sideToSideTilt, 0));
                c2->setAngularUpperLimit(btVector3(0, sideToSideTilt, 0));

                createJoint(c2);

                rightElbowMotor = new SixDoFMotor(brain, c2, 0.001, M_PI_4, 0.1, 0.1);
            }
        }

        brain->init();
        brain->printSummary();

    }

    virtual btVector3 getColor(btCollisionShape* shape) {
        float i = (float) (indexOfShape(shape) % 2);
        return btVector3(0.3 + i * 0.5, 0.8 + i * 0.2, 0.4);
    }

    virtual void process(btScalar dt) {

        //inputs
        eyeRetina->process(dt);
        lhRetina->process(dt);

        //brain
        brain->forward(dt);

        //outputs
        neckMotor->process(dt);
        leftShoulderMotor->process(dt);
        rightShoulderMotor->process(dt);
        leftElbowMotor->process(dt);
        rightElbowMotor->process(dt);

    }

    virtual ~Humanoid() {
        unsigned i;

        // Remove all constraints
        for (i = 0; i < joints.size(); ++i) {
            dyn->removeConstraint(joints[i]);
            delete joints[i];
            joints[i] = 0;
        }

        // Remove all bodies and shapes
        for (i = 0; i < bodies.size(); ++i) {
            dyn->removeRigidBody(bodies[i]);

            delete bodies[i]->getMotionState();

            delete bodies[i];
            bodies[i] = 0;
            delete shapes[i];
            shapes[i] = 0;
        }
    }


};

#endif /* HUMANOID_H_ */
