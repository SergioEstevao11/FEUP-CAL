//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_BIDIJKSTRA_H
#define VACCINEROUTER_BIDIJKSTRA_H


#include "../graph/Graph.h"

#include <vector>

class BiDijkstra {
private:
    Graph * graph;
    std::unordered_map<Node *, double> distForward;
    std::unordered_map<Node *, double> distBackward;
    std::unordered_map<Node *, Edge *> path;
    std::unordered_map<Node*, bool> visitedForward;
    std::unordered_map<Node*, bool> visitedBackward;
    void setup();
public:
    BiDijkstra(Graph * graph);
    double run(Node * orig, Node* dest);
    std::vector<Edge *> getPath(Node * source, Node * dist);
};


#endif //VACCINEROUTER_BIDIJKSTRA_H
