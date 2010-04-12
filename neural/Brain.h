/*
 * Brain.h
 *
 *  Created on: Jan 21, 2010
 *      Author: seh
 */

#ifndef BRAIN_H_
#define BRAIN_H_

#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

using namespace std;

#include "../math/Math.h"
#include "Neuron.h"

class Brain {
public:
    int neuronsFired;
    int outNeuronsFired;

    int totalSynapses;

    vector<Neuron*> neurons;
    vector<InNeuron*> ins;
    vector<OutNeuron*> outs;

    vector<float> inValues;
    vector<float> outValues;

    vector<NeuronBuilder*> neuronBuilders;

    unsigned numNeurons;
    unsigned minSynapses;
    unsigned maxSynapses;

    float percentChanceInhibitoryNeuron;
    float percentChanceConsistentSynapses;
    float percentChanceInhibitorySynapses;

    float percentChanceOutputNeuron;
    float percentChancePlasticNeuron;
    float percentChanceInputSynapse;

    float minPlasticityStrengthen;
    float maxPlasticityStrengthen;
    float minPlasticityWeaken;
    float maxPlasticityWeaken;

    float minFiringThreshold;
    float maxFiringThreshold;

    //float maxDendridicBranches;
    //float percentMutation;


    //Usage: create the brain, attach peripherals, then call 'init()' to wire them

    Brain(unsigned _numNeurons, unsigned _minSynapsesPerNeuron, unsigned _maxSynapsesPerNeuron, float _percentInhibitory) {

        numNeurons = _numNeurons;
        minSynapses = _minSynapsesPerNeuron;
        maxSynapses = _maxSynapsesPerNeuron;

        percentChanceInhibitoryNeuron = _percentInhibitory;
        percentChanceInhibitorySynapses = _percentInhibitory;


        initDefaults();
    }


    //DEPRECATED
    Brain(unsigned numInputs, unsigned numOutputs, unsigned _numNeurons, unsigned _minSynapsesPerNeuron, unsigned _maxSynapsesPerNeuron, float _percentInhibitory) {
        numNeurons = _numNeurons;
        minSynapses = _minSynapsesPerNeuron;
        maxSynapses = _maxSynapsesPerNeuron;

        percentChanceInhibitoryNeuron = _percentInhibitory;
        percentChanceInhibitorySynapses = _percentInhibitory;

        for (unsigned i = 0; i < numInputs; i++)
            newInput();

        for (unsigned i = 0; i < numOutputs; i++)
            newOutput();

        initDefaults();
        init();

    }

    Brain() {
    }

    int getNeuronIndex(AbstractNeuron* a) {
        for (unsigned i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            if (n == a)
                return i;
        }
        return -1;
    }

    void initDefaults() {
        minPlasticityStrengthen = 1.01;
        maxPlasticityStrengthen = 1.200;
        minPlasticityWeaken = 0.800;
        maxPlasticityWeaken = 0.99;


        percentChanceConsistentSynapses = 0.10;

        percentChancePlasticNeuron = 0.75;

        percentChanceOutputNeuron = 0.25;
        percentChanceInputSynapse = 0.25;

        minFiringThreshold = 0.51;

        maxFiringThreshold = 0.99;

    }

    InNeuron* newInput() {
        InNeuron* i = new InNeuron();
        ins.push_back(i);
        inValues.resize(ins.size(), 0);
        return i;
    }

    OutNeuron* newOutput() {
        OutNeuron* o = new OutNeuron();
        outs.push_back(o);
        outValues.resize(outs.size(), 0);
        return o;
    }

    InNeuron* getRandomInNeuron() {
        int i = irand(0, ins.size());
        return ins[i];
    }

    OutNeuron* getRandomOutNeuron() {
        int i = irand(0, outs.size());
        return outs[i];
    }

    Neuron* getRandomInterNeuron() {
        int i = irand(0, neurons.size());
        return neurons[i];
    }

    void addRandomInputs(double minValue, double maxValue, double decay) {
        for (unsigned i = 0; i < ins.size(); i++) {
            InNeuron* n = ins[i];
            n->setInput((n->getInput() + frand(minValue, maxValue)) * decay);
        }

    }

    void resetInputs() {
        for (unsigned i = 0; i < ins.size(); i++) {
            InNeuron* n = ins[i];
            n->setInput(0.0);
        }
    }

    void resetOutputs() {
        for (unsigned i = 0; i < outs.size(); i++) {
            OutNeuron* n = outs[i];
            n->reset();
        }
    }

    // build time functions

    NeuronBuilder* newRandomNeuronBuilder() {
        // new architectural neuron
        NeuronBuilder* an = new NeuronBuilder();

        // is it inhibitory ?
        if (frand(0, 1) <= percentChanceInhibitoryNeuron) {
            an->isInhibitory = true;
        }// if not, is it motor ?
        else {
            an->isInhibitory = false;
        }
        
        if (frand(0, 1) <= percentChanceOutputNeuron) {
            OutNeuron* mn = getRandomOutNeuron();

            // check if motor already used
            //            bool proceed = true;
            //            for (NeuronBuilder nb : neuronBuilders) {
            //                if (nb.motor == mn) {
            //                    proceed = false;
            //                    break;
            //                }
            //            }

            //if (proceed) {

            //Allows a motor neuron to receive multiple inputs
            an->out = mn;
            //}
        }

        // does it have synaptic plasticity ?
        if (frand(0, 1) <= percentChancePlasticNeuron) {
            an->isPlastic = true;
            an->plasticityStrengthen = frand(minPlasticityStrengthen, maxPlasticityStrengthen);
            an->plasticityWeaken = frand(minPlasticityWeaken, maxPlasticityWeaken);
        } else {
            an->isPlastic = false;
            an->plasticityStrengthen = (minPlasticityStrengthen + maxPlasticityStrengthen)/2.0;
            an->plasticityWeaken = (minPlasticityWeaken + maxPlasticityWeaken) / 2.0;
        }

        // does it have consistent synapses ?
        if (frand(0, 1) <= percentChanceConsistentSynapses) {
            an->hasConsistentSynapses = true;

            // if so, does it have inhibitory synapses ?
            if (frand(0, 1) <= percentChanceInhibitorySynapses) {
                an->hasInhibitorySynapses = true;
            }
        }

        // determine firing threshold
        if (an->out != NULL) {
            an->firingThreshold = maxFiringThreshold;
            //an->maxDendridicBranches = maxDendridicBranches;
        } else {
            an->firingThreshold = frand(minFiringThreshold, maxFiringThreshold);
            //an->maxDendridicBranches = irand(1, maxDendridicBranches);
        }



        return an;
    }

    SynapseBuilder* newRandomSynapseBuilder(NeuronBuilder* bn) {
        // new architectural synapse
        SynapseBuilder* as = new SynapseBuilder();

        // is it connected to a sensor neuron ?
        // < 2 because if only 1 archneuron, it can't connect to other one
        if (frand(0, 1) <= percentChanceInputSynapse || neuronBuilders.size() < 2) {
            as->isSensorNeuron = true;

            // sensor neuron id synapse is connected to
            //cout << "inNeuron = random in neuron\n";
            as->inNeuron = getRandomInNeuron();
        }// if not determine inter neuron id
        else {
            as->isSensorNeuron = false;
            // as in real life, neurons can connect to themselves
            //cout << "inNeuron = random neuron\n";
            as->inNeuron = getRandomInterNeuron();
        }

        // dendrite branch number
        //as->dendriteBranches = irand(0, bn->maxDendriteBranches);

        // synaptic weight
        if (bn->hasConsistentSynapses) {
            as->weight = (bn->hasInhibitorySynapses) ? -1.0 : 1.0;
        } else {
            as->weight = (frand(0, 1) <= percentChanceInhibitorySynapses) ? -1.0 : 1.0;
        }

        //bn->synapseBuilders.push_back(as);

        return as;
    }

    void init() {

        // determine number of neurons this brain will start with
        //int numNeurons = (int) Math.round(Maths.random(minNeuronsAtBuildtime, maxNeuronsAtBuildtime));

        totalSynapses = 0;

        // create the architectural neurons
        for (unsigned i = 0; i < numNeurons; i++) {
            NeuronBuilder *nb = newRandomNeuronBuilder();
            neuronBuilders.push_back(nb);

        }


        // clear everything
        //neuron.clear();
        //sense.clear();
        //motor.clear();

        // we know the amount of neurons already, reset totalsynapses for the count later


        // create all runtime neurons
        for (unsigned i = 0; i < neuronBuilders.size(); i++) {
            NeuronBuilder* nb = neuronBuilders[i];
            Neuron* n = nb->newNeuron(maxSynapses);
            neurons.push_back(n);

            // determine amount of synapses this neuron will start with
            int numSynapses = irand(minSynapses, maxSynapses);

            // create the architectural neurons
            for (int j = 0; j < numSynapses; j++) {
                SynapseBuilder* sb = newRandomSynapseBuilder(nb);

                Synapse* s = new Synapse(sb->inNeuron, sb->weight);
                n->synapses.push_back(s);
                totalSynapses++;
            }


        }

    }

    void forward(float dt) {
        //TODO handle 'dt' appropriately

        // reset fired neurons counter
        neuronsFired = outNeuronsFired = 0;

        resetOutputs();

        inValues.reserve(ins.size());
        for (unsigned i = 0; i < ins.size(); i++) {
            inValues[i] = ins[i]->getInput();
        }

        for (unsigned i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            n->forward(dt);

            // if neuron fires
            if (n->nextOutput != 0) {
                neuronsFired++;

                // motor neuron check & exec
                OutNeuron* mn = n->target;
                if (mn != NULL) {
                    outNeuronsFired++;
                    mn->stimulate(n->nextOutput);
                }
            }
        }

        // commit outputs at the end
        for (unsigned i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            n->output = n->nextOutput;
        }

        outValues.reserve(outs.size());
        for (unsigned i = 0; i < outs.size(); i++) {
            outValues[i] = outs[i]->getOutput();
        }

    }

    void forwardParallel(float dt) {
        //TODO handle 'dt' appropriately

        // reset fired neurons counter
        neuronsFired = outNeuronsFired = 0;

        resetOutputs();

        unsigned i;
#pragma omp parallel for private(i)
        for (i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            n->forward(dt);

            // if neuron fires
            if (n->nextOutput != 0) {
                neuronsFired++;

                // motor neuron check & exec
                OutNeuron* mn = n->target;
                if (mn != NULL) {
                    outNeuronsFired++;
                    mn->stimulate(n->nextOutput);
                }
            }
        }

        // commit outputs at the end
#pragma omp parallel for private(i)
        for (i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            n->output = n->nextOutput;
        }

    }

    void printSummary() {
        cout << "Brain" << '\n';
        cout << "  ins/outs: " << ins.size() << "|" << outs.size() << '\n';
        cout << "  Neurons: " << numNeurons << '\n';
        cout << "  Synapses: " << totalSynapses << '\n';
        cout << "  Avg Synapses/Neuron: " << ((float) totalSynapses) / ((float) numNeurons) << '\n';
        cout << "    Min Synapses: " << minSynapses << '\n';
        cout << "    Max Synapses: " << maxSynapses << '\n';
    }

    void print() {
        printSummary();

        cout << '\n';

        for (unsigned i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            n->print();
        }

    }

    void setPotentialDecay(double pd) {
        for (unsigned i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            n->potentialDecay = pd;
        }
        cout << "All neurons have potentialDecay=" << pd << "\n";
    }

    void setFiringThreshold(double ft) {
        for (unsigned i = 0; i < neurons.size(); i++) {
            Neuron* n = neurons[i];
            n->firingThreshold = ft;
        }
        cout << "All neurons have firingThreshold=" << ft << "\n";
    }

};

#endif /* BRAIN_H_ */
