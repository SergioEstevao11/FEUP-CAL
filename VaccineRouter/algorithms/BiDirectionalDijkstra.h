//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_BIDIRECTIONALDIJKSTRA_H
#define VACCINEROUTER_BIDIRECTIONALDIJKSTRA_H


#include "../graph/Graph.h"

class BiDirectionalDijkstra {
private:
    Graph * graph;
    std::unordered_map<Node *, double> distForward;
    std::unordered_map<Node *, double> distBackward;
    std::unordered_map<Node *, Node *> path;
    std::unordered_map<Node*, bool> visitedForward;
    std::unordered_map<Node*, bool> visitedBackward;
    void setup();
public:
    BiDirectionalDijkstra(Graph * graph);
    double run(Node * orig, Node* dest);
};


#endif //VACCINEROUTER_BIDIRECTIONALDIJKSTRA_H
