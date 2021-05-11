//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_BIASTAR_H
#define VACCINEROUTER_BIASTAR_H


#include "../graph/Graph.h"

class BiAStar {
private:
    Graph * graph;
    std::unordered_map<Node *, double> distForward;
    std::unordered_map<Node *, double> distBackward;
    std::unordered_map<Node *, Node *> path;
    std::unordered_map<Node*, bool> visitedForward;
    std::unordered_map<Node*, bool> visitedBackward;
    std::unordered_map<Node*, double> heuristicForward;
    std::unordered_map<Node*, double> heuristicBackward;
    void setup(Node * orig, Node* dest);
public:
    BiAStar(Graph * graph);
    double run(Node * orig, Node* dest);
};


#endif //VACCINEROUTER_BIASTAR_H
