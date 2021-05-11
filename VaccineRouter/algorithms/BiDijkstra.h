//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_BIDIJKSTRA_H
#define VACCINEROUTER_BIDIJKSTRA_H


#include "../graph/Graph.h"

class BiDijkstra {
private:
    Graph * graph;
    std::unordered_map<Node *, double> distForward;
    std::unordered_map<Node *, double> distBackward;
    std::unordered_map<Node *, Node *> path;
    std::unordered_map<Node*, bool> visitedForward;
    std::unordered_map<Node*, bool> visitedBackward;
    void setup();
public:
    BiDijkstra(Graph * graph);
    double run(Node * orig, Node* dest);
};


#endif //VACCINEROUTER_BIDIJKSTRA_H
