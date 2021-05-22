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
    std::unordered_map<Node*,Node*> SCC;
    std::unordered_map<Node*,bool> visited;
    std::stack<Node*> stack;
    unsigned int executionTime;
    void setup();
    void DFSFirst(Node * node);
    void DFSAssign(Node * node, Node * component);
public:
    Kosaraju(Graph * graph);
    void run();
    std::unordered_map<Node*,Node*> getSCC();
    unsigned int getExecutionTime();

};


#endif //VACCINEROUTER_KOSARAJU_H
