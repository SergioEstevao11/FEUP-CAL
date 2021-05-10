//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_DIJKSTRA_H
#define VACCINEROUTER_DIJKSTRA_H


#include <queue>
#include "../graph/Graph.h"

#include <unordered_map>
#include <queue>

class Dijkstra {
private:
    Graph * graph;
    //std::unordered_map<Node *, double> dist; USED FOR TESTING
    std::unordered_map<Node *, Node *> path;
    //std::unordered_map<Node*, bool> visited;
    void setup();
public:
    Dijkstra(Graph * g);
    std::unordered_map<Node *, double> dist;
    std::unordered_map<Node*, bool> visited;
    void run(Node* node);
};


#endif //VACCINEROUTER_DIJKSTRA_H
