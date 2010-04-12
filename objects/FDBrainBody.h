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

    btVector3 minXYZ, maxXYZ;

public:
    bool center;
    float naturalLength;
    float repulsion;
    float tension;
    float speed;
    float neuronSize;

    FDBrainBody(Brain* b, float w, float h, float d) : brain(b) {

        minXYZ = btVector3(-w/2.0, -h/2.0, -d/2.0);
        maxXYZ = btVector3(w/2.0, h/2.0, d/2.0);

        naturalLength = 12.0;
        repulsion = 0.0;
        tension = 0.1;
        speed = 0.1;
        neuronSize = 0.5;
        center = true;
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

            if (n->target != NULL)
                neuronShape[i] = new btSphereShape(1.0);
            else
                neuronShape[i] = new btBoxShape(btVector3(1.0, 1.0, 1.0));

            shapeToNeuron[neuronShape[i]] = n;
            neuronToBody[n] = bodies[i] = neuronBody[i] = createRigidShape(btScalar(0.1), transform, neuronShape[i]);
            bodies[i]->setGravity( btVector3(0,0,0) );
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
            float s = neuronSize;
            float w = s * (1.0 + (fabs(brain->neurons[i]->getOutput())));
            float h = s * (1.0 + sqrt(fabs(brain->neurons[i]->potential)));
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
                float targetLength = neuronSize * naturalLength * (2.0 - fabs(syn->weight)); // / (1.0 + fabs(syn->weight));
                float f = tension * (currentLength - targetLength)/* / ((float) numSynapses)*/;

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

            aPos[0] = fmax(fmin(aPos[0], maxXYZ[0]), minXYZ[0]);
            aPos[1] = fmax(fmin(aPos[1], maxXYZ[1]), minXYZ[1]);
            aPos[2] = fmax(fmin(aPos[2], maxXYZ[2]), minXYZ[2]);
            
            aBod->getWorldTransform().setOrigin(aPos);

            center += aPos;
        }

        center /= ((double) brain->numNeurons);

        if (center) {
            #pragma omp parallel for private(i)
            for (i = 0; i < brain->numNeurons; i++) {
                btRigidBody *aBod = neuronBody[i];
                btVector3 pos = aBod->getWorldTransform().getOrigin();
                aBod->getWorldTransform().setOrigin(pos - center);
            }
        }


    }

    virtual void draw() {
        glBegin(GL_TRIANGLES);
        
        for (unsigned i = 0; i < brain->numNeurons; i++) {
            Neuron* a = brain->neurons[i];
            btRigidBody *aBod = neuronBody[i];

            btVector3 aPos = aBod->getWorldTransform().getOrigin();
            btVector3 axis = aBod->getWorldTransform().getRotation().getAxis().normalized();
            double aax = axis.getX();
            double aay = axis.getY();

            unsigned numSynapses = a->synapses.size();
            for (unsigned s = 0; s < numSynapses; s++) {
                Synapse* syn = a->synapses[s];
                AbstractNeuron *b = syn->inputNeuron;
                if (b == NULL) {
                    cout << "synapse " << s << " has NULL inputNeuron\n";
                    continue;
                }

                btRigidBody *bBod = neuronToBody[b];
                if (bBod == NULL) {
                    continue;
                }

                btVector3 bPos = bBod->getWorldTransform().getOrigin();
                //double bbx = bBod->getOrientation().getAxis().getX();
                //double bby = bBod->getOrientation().getAxis().getY();

                float w = syn->weight;
                float input = neuronSize * (0.5 + 0.5 * fmin(fabs(a->potential), 1.0));
                float cr, cg, cb, ca;
                if (w < 0) {
                    cr = fmin(0.5 + -w/2.0, 1.0);
                    cg = 0.25;
                    cb = 0.25;
                    ca = 0.5;
                }
                else {
                    cb = fmin(0.5 + w/2.0, 1.0);
                    cr = 0.25;
                    cg = 0.25;
                    ca = 0.5;
                }

                glColor4f(cr, cg, cb, ca);

                glVertex3f(aPos.getX()+aax*input, aPos.getY(), aPos.getZ());
                glVertex3f(aPos.getX()-aax*input, aPos.getY(), aPos.getZ());
                glVertex3f(bPos.getX(), bPos.getY(), bPos.getZ());

            }

        }
        glEnd();

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

