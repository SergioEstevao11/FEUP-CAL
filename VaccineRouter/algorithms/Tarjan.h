//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_TARJAN_H
#define VACCINEROUTER_TARJAN_H


#include <stack>

#include "../graph/Graph.h"

class Tarjan {
private:
    Graph * graph;
    std::unordered_map<Node*,Node*> SCC;
    std::unordered_map<Node*,int> id;
    std::unordered_map<Node*,int> lowLink;
    std::unordered_map<Node*,bool> onStack;
    std::stack<Node*> stack;
    int index;
    unsigned int executionTime;
    void setup();
    void strongComponent(Node * node);
public:
    Tarjan(Graph * graph);
    void run();
    std::unordered_map<Node*,Node*> getSCC();
    unsigned int getExecutionTime();
};


#endif //VACCINEROUTER_TARJAN_H
