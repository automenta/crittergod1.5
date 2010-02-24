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

#include "../widget2d/panel.h"
#include "../widget2d/slider.h"
#include "../widget2d/button.h"

class FDBrainBody : public AbstractBody {
    Brain* brain;

    vector<btCollisionShape*> neuronShape;
    vector<btRigidBody*> neuronBody;
    map<AbstractNeuron*, btRigidBody*> neuronToBody;
    map<btCollisionShape*, AbstractNeuron*> shapeToNeuron;


public:
    float naturalLength;
    float repulsion;
    float tension;
    float speed;

    FDBrainBody(Brain* b) : brain(b) {

        naturalLength = 7.5;
        repulsion = 0.0;
        tension = 0.1;
        speed = 0.1;
    }

    virtual void init() {

        unsigned int numNeurons = brain->neurons.size();

        bodies.reserve(numNeurons);
        shapes.reserve(numNeurons);

        neuronShape.reserve(numNeurons);
        neuronBody.reserve(numNeurons);
        joints.reserve(0);

        for (unsigned i = 0; i < numNeurons; i++) {
            Neuron* n = brain->neurons[i];

            btTransform transform;
            transform.setIdentity();
            transform.setOrigin(btVector3(frand(-5, 5), frand(-5, 5), frand(-5, 5)));

            if (n->target!=NULL)
                neuronShape[i] = new btSphereShape(1.0);
            else
                neuronShape[i] = new btBoxShape(btVector3(1.0, 1.0, 1.0));
            
            shapeToNeuron[neuronShape[i]] = n;
            neuronToBody[n] = bodies[i] = neuronBody[i] = createRigidShape(btScalar(1.), transform, neuronShape[i]);
        }

    }

    virtual btVector3 getColor(btCollisionShape* shape) {
        AbstractNeuron *an = shapeToNeuron[shape];
        if (an != NULL) {
            Neuron* neuron = dynamic_cast<Neuron*> (an);
            if (neuron != NULL) {
                return btVector3(0.5 * (1.0 + neuron->potential), 0.5 * (1.0 + neuron->getOutput()), 0.5);
            } else {
                return btVector3(0.5 * (1.0 + an->getOutput()), 0.5, 0.5);
            }
        }
        return btVector3(0.5, 0.5, 0.5);
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

        //update shape sizes
        for (unsigned i = 0; i < numNeurons; i++) {
            btCollisionShape* bt = neuronShape[i];
            float s = 0.5;
            float w = s * (1.0 + (fabs(brain->neurons[i]->getOutput())));
            float h = s * (1.0 + (fabs(brain->neurons[i]->potential)));
            bt->setLocalScaling(btVector3(w, h, (w + h) / 2.0));            
        }

        //attract
        btVector3 center(0, 0, 0);

        unsigned i;
        #pragma omp parallel for private(i)
        for (i = 0; i < brain->numNeurons; i++) {
            Neuron* a = brain->neurons[i];
            btRigidBody *aBod = neuronBody[i];
            btVector3 aPos = aBod->getWorldTransform().getOrigin();

            unsigned numSynapses = a->synapses.size();
            for (unsigned s = 0; s < numSynapses; s++) {
                Synapse* syn = a->synapses[s];
                AbstractNeuron *b = syn->inputNeuron;
                if (b == NULL)
                    continue;

                btRigidBody *bBod = neuronToBody[b];
                if (bBod == NULL)
                    continue;

                btVector3 bPos = bBod->getWorldTransform().getOrigin();

                float currentLength = aPos.distance(bPos);
                float f = tension * (currentLength - naturalLength)/* / ((float) numSynapses)*/;

                float sx = f * (bPos.getX() - aPos.getX());
                float sy = f * (bPos.getY() - aPos.getY());
                float sz = f * (bPos.getZ() - aPos.getZ());

                aPos += btVector3(sx / 2.0, sy / 2.0, sz / 2.0) * speed;
                bPos -= btVector3(sx / 2.0, sy / 2.0, sz / 2.0) * speed;

                aBod->getWorldTransform().setOrigin(aPos);
                bBod->getWorldTransform().setOrigin(bPos);

            }
        }

        //repel
        for (i = 0; i < brain->numNeurons; i++) {
            Neuron* a = brain->neurons[i];
            btRigidBody *aBod = neuronBody[i];
            btVector3 aPos = aBod->getWorldTransform().getOrigin();

            if (repulsion != 0.0) {
                btVector3 force(0, 0, 0);

                unsigned j;
                #pragma omp parallel for private(j)
                for (j = 0; j < brain->numNeurons; j++) {
                    if (i == j)
                        continue;

                    btRigidBody *bBod = neuronBody[j];
                    if (bBod == NULL)
                        continue;

                    btVector3 bPos = bBod->getWorldTransform().getOrigin();

                    double dist = bPos.distance(aPos);

                    double f = repulsion * /*(nMass * mMass)*/1.0 / (dist * dist);
                    
                    double sx = f * (aPos.getX() - bPos.getX());
                    double sy = f * (aPos.getY() - bPos.getY());
                    double sz = f * (aPos.getZ() - bPos.getZ());
                    force += btVector3(sx, sy, sz);
                }
                
                aPos += force * speed;
            }
            aBod->getWorldTransform().setOrigin(aPos);

            center += aPos;
        }

        center /= ((double) brain->numNeurons);

        #pragma omp parallel for private(i)
        for (i = 0; i < brain->numNeurons; i++) {
            btRigidBody *aBod = neuronBody[i];
            btVector3 pos = aBod->getWorldTransform().getOrigin();
            aBod->getWorldTransform().setOrigin(pos - center);
        }


    }

    virtual ~FDBrainBody() {

    }
private:

};

class FDBrainPanel : public Panel, SliderModel {
    FDBrainBody* fd;

    HSlider* lengthSlider;
    HSlider* repelSlider;
    HSlider* tensionSlider;

public:

    FDBrainPanel(FDBrainBody* _fd) : Panel(), fd(_fd) {

        lengthSlider = new HSlider(&(fd->naturalLength), 4.0, 24.0);
        lengthSlider->span(5, 5, 90, 35);
        addPanel("natLength", lengthSlider);

        repelSlider = new HSlider(&(fd->repulsion), -0.1, 2.0);
        repelSlider->span(5, 35, 90, 65);
        addPanel("repulsion", repelSlider);

        tensionSlider = new HSlider(&(fd->tension), 0, 1.0);
        tensionSlider->span(5, 70, 90, 100);
        addPanel("tension", tensionSlider);

    }
};

#endif	/* _FDBRAINBODY_H */

