//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_KOSARAJU_H
#define VACCINEROUTER_KOSARAJU_H


#include "../graph/Graph.h"

#include<stack>

class Kosaraju {
private:
    Graph * graph;
    //std::unordered_map<Node*,Node*> SCC;
    std::unordered_map<Node*,bool> visited;
    std::stack<Node*> stack;
    void setup();
    void DFSFirst(Node * node);
    void DFSAssign(Node * node, Node * component);
public:
    std::unordered_map<Node*,Node*> SCC;
    Kosaraju(Graph * graph);
    void run();

};


#endif //VACCINEROUTER_KOSARAJU_H
