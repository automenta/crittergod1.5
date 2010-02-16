/*
 * Graph.h
 *
 *  Created on: Feb 8, 2010
 *      Author: seh
 */

#ifndef GRAPH_H_
#define GRAPH_H_

using namespace std;

#include <iostream>
#include <map>
#include <vector>

class Graph {
private:
	map< void*,vector<void*>* > vertices;
	map< void*,vector<void*>* > edges;

public:
	Graph();
	virtual ~Graph();

	bool addEdge(void* e, void* a, void* b) {
		vector<void*>* l = new vector<void*>(2);
		(*l)[0] = a;
		(*l)[1] = b;
		addEdge(e, l);
	}

	bool addEdge(void* e, vector<void*>* v) {
		vector<void*>* existing = edges[e];
		if (existing != NULL) {
			//compare vertices to existing and warn if changed?
			return false;
		}

		for (unsigned i = 0; i < v->size(); i++) {
			void* x = (*v)[i];
			if (!addVertex(x)) {
				return false;
			}
			vertices[x]->push_back( e );
		}

		edges[e] = v;

		return true;
	}

	bool addVertex(void* v) {
		vertices[v] = new vector<void*>();
		return true;
	}

	bool removeVertex(void* v) { }
	bool removeEdge(void* e) { }


	bool containsVertex(void* v) {
		return (vertices[v]!=NULL);
	}
	bool containsEdge(void* e) {
		return (edges[e]!=NULL);
	}

	bool isIncident(void* v, void* e) {
		if (!containsVertex(v) || !containsEdge(e))
			return false;

		vector<void*>* el = vertices[v];
    	vector<void*>::const_iterator li;
    	for (li = el->begin(); li != el->end(); ++li) {
    		if (*li == e)
    			return true;
    	}

    	return false;
	}

//public H findEdge(V v1, V v2)
//{
//    if (!containsVertex(v1) || !containsVertex(v2))
//        return null;
//
//    for (H h : getIncidentEdges(v1))
//    {
//        if (isIncident(v2, h))
//            return h;
//    }
//    return null;
//}

//public boolean isNeighbor(V v1, V v2)
//{
//    if (!containsVertex(v1) || !containsVertex(v2))
//        return false;
//
//    if (vertices.get(v2).isEmpty())
//        return false;
//    for (H hyperedge : vertices.get(v1))
//    {
//        if (edges.get(hyperedge).contains(v2))
//            return true;
//    }
//    return false;
//}

	unsigned degree(void* v) {
		if (!containsVertex(v))
			return 0;
		return vertices[v]->size();
	}

	void print() {
	    map<void*, vector<void*>* >::const_iterator iter;
	    for (iter=edges.begin(); iter != edges.end(); ++iter) {
	    	vector<void*>* v = iter->second;

	    	cout << *((string*)iter->first) << "\n";

	    	vector<void*>::const_iterator li;
	    	for (li = v->begin(); li != v->end(); ++li) {
		    	cout << "  " << *li << "\n";
	    	}

	    }
		//cout << edges.;
	}
};

#endif /* GRAPH_H_ */
