/* 
 * File:   RunTests.cpp
 * Author: seh
 * 
 * Created on February 23, 2010, 3:59 PM
 */

#include "graph/Graph.h"
#include "RunTests.h"



void testGraph() {
    Graph g;

    string a = string("a");
    string b = string("b");

    g.addEdge(new string("ab"), &a, &b);
    g.addEdge(new string("cd"), &a, &b);

    g.print();

}
