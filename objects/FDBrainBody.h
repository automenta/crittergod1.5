/* 
 * File:   FDBrainBody.h
 * Author: seh
 *
 * Created on February 22, 2010, 3:26 PM
 */

#ifndef _FDBRAINBODY_H
#define	_FDBRAINBODY_H

using namespace std;
#include <iostream>
#include <vector>
#include <map>

#include "../neural/Brain.h"
#include "../space/AbstractBody.h"

class FDBrainBody : public AbstractBody {
    Brain* brain;

    vector<btCollisionShape*> neuronShape;
    vector<btRigidBody*> neuronBody;
    map<AbstractNeuron*, btRigidBody*> neuronToBody;
    map<btCollisionShape*, AbstractNeuron*> shapeToNeuron;
    

public:

    FDBrainBody(Brain* b) : brain(b) {

    }

    virtual void init() {

        unsigned int numNeurons = brain->neurons.size();

        bodies.reserve(numNeurons);
        shapes.reserve(numNeurons);
        
        neuronShape.reserve(numNeurons);
        neuronBody.reserve(numNeurons);
        joints.reserve(0);

        for (unsigned i = 0; i < numNeurons; i++) {
            AbstractNeuron* n = brain->neurons[i];
            
            neuronShape[i] = new btBoxShape(btVector3(0.25, 0.25, 0.25));
            shapes.push_back(neuronShape[i]);
            shapeToNeuron[neuronShape[i]] = n;

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(btVector3(frand(-5,5), frand(-5,5), frand(-5,5)));

            bodies[i] = neuronBody[i] = localCreateRigidBody(btScalar(1.), transform, neuronShape[i]);
            bodies[i]->setDamping(0.05, 0.85);
            bodies[i]->setDeactivationTime(0.8);
            bodies[i]->setSleepingThresholds(0.5f, 0.5f);

            neuronToBody[n] = bodies[i];

        }

    }

    virtual btVector3 getColor(btCollisionShape* shape) {
        AbstractNeuron *an = shapeToNeuron[shape];
        if (an!=NULL) {
            Neuron* neuron = dynamic_cast<Neuron*>(an);
            if (neuron!=NULL) {
                return btVector3(0.5 * (1.0 + neuron->potential), 0.5, 0.5);
            }
            else {
                return btVector3(0.5 * (1.0 + an->getOutput()), 0.5, 0.5);
            }
        }
        return btVector3(0.5,0.5,0.5);
    }


    virtual void process(btScalar dt) {

        btVector3 d(0, 0, 0);


        //    double wx = getBoundsMax().getX() / 2.0;
        //    double wy = getBoundsMax().getY() / 2.0;
        //    double wz = getBoundsMax().getZ() / 2.0;

        //update inputs
        {
            brain->addRandomInputs(-0.2, 0.2, 0.99);
        }
        brain->forward(1.0);

        unsigned int numNeurons = brain->neurons.size();

        for (unsigned i = 0; i < numNeurons; i++) {
            btCollisionShape* bt = neuronShape[i];
            double w = 0.25 * (2 + brain->neurons[i]->getOutput() + brain->neurons[i]->potential);
            bt->setLocalScaling(btVector3(w, w, w));
        }


        double stiffness = 0.1;
        double repulsion = 0; //-0.0001;
        double naturalLength = 1.5;
        double speed = 0.03;

//        		for (unsigned i = 0; i < brain->numNeurons; i++) {
//        			Neuron* n = brain->neurons[i];
//        			d.setValue(frand(-4.0002, 4.0002), frand(-4.0002, 4.0002), frand(-4.0002, 4.0002));
//                                btTransform t;
//                                t.setOrigin(d);
//        			neuronBody[i]->setCenterOfMassTransform(t);
//        		}

        //attract
        unsigned i;
        btVector3 center(0, 0, 0);

        #pragma omp parallel for private(i)
        for (i = 0; i < brain->numNeurons; i++) {
            Neuron* a = brain->neurons[i];
            btRigidBody *aBod = neuronBody[i];
            btVector3 aPos = aBod->getCenterOfMassPosition();
            
            unsigned numSynapses = a->synapses.size();
            for (unsigned s = 0; s < numSynapses; s++) {
                Synapse* syn = a->synapses[s];
                AbstractNeuron *b = syn->inputNeuron;
                if (b == NULL)
                    continue;

                btRigidBody *bBod = neuronToBody[b];
                if (bBod == NULL)
                    continue;

                btVector3 bPos = bBod->getCenterOfMassPosition();
                
                double currentLength = aPos.distance(bPos);
                double f = stiffness * (currentLength - naturalLength) / ((float) numSynapses);

                double sx = f * (bPos.getX() - aPos.getX());
                double sy = f * (bPos.getY() - aPos.getY());
                double sz = f * (bPos.getZ() - aPos.getZ());

                aPos += btVector3(sx / 2.0, sy / 2.0, sz / 2.0) * speed;
                bPos -= btVector3(sx / 2.0, sy / 2.0, sz / 2.0) * speed;

                aBod->getWorldTransform().setOrigin(aPos);
                bBod->getWorldTransform().setOrigin(bPos);

            }
        }

        //repel

//        //#pragma omp parallel for private(i)
//        for (i = 0; i < brain->numNeurons; i++) {
//            Neuron* a = brain->neurons[i];
//            btRigidBody *aBod = neuronBody[i];
//            btVector3 aPos = aBod->getCenterOfMassPosition();
//
//            if (repulsion != 0.0) {
//                btVector3 force(0, 0, 0);
//                for (unsigned j = 0; j < brain->numNeurons; j++) {
//                    if (i == j)
//                        continue;
//
//                    btRigidBody *bBod = neuronBody[j];
//                    btVector3 bPos = bBod->getCenterOfMassPosition();
//                    if (bBod == NULL)
//                        continue;
//
//                    double dist = bPos->distance(*aPos);
//
//                    double f = -repulsion * /*(nMass * mMass)*/1.0 / (dist * dist);
//
//                    double sx = f * (aPos->getX() - bPos->getX());
//                    double sy = f * (aPos->getY() - bPos->getY());
//                    double sz = f * (aPos->getZ() - bPos->getZ());
//                    force += btVector3(sx, sy, sz);
//                }
//
//                *aPos += force * speed;
//
//            }
//
//            center += *aPos;
//        }

        center /= ((double) brain->numNeurons);

        //#pragma omp parallel for private(i)
        for (i = 0; i < brain->numNeurons; i++) {
            Neuron* a = brain->neurons[i];
            btRigidBody *aBod = neuronBody[i];
            btVector3 pos = aBod->getWorldTransform().getOrigin();
            aBod->getWorldTransform().setOrigin(pos-center);
            //(neuronBody[i]->getCenterOfMassPosition()
//                    -=center;
        }


    }

    virtual ~FDBrainBody() {

    }
private:

};

#endif	/* _FDBRAINBODY_H */

