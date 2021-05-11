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
    //std::unordered_map<Node*,Node*> SCC;
    std::unordered_map<Node*,int> id;
    std::unordered_map<Node*,int> lowLink;
    std::unordered_map<Node*,bool> onStack;
    std::stack<Node*> stack;
    int index;
    void setup();
    void strongComponent(Node * node);
public:
    std::unordered_map<Node*,Node*> SCC;
    Tarjan(Graph * graph);
    void run();
};


#endif //VACCINEROUTER_TARJAN_H