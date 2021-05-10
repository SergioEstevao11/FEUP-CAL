//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_NODETOALL_H
#define VACCINEROUTER_NODETOALL_H


#include <queue>
#include "../graph/Graph.h"

#include <unordered_map>
#include <queue>

class NodeToAll {
private:
    Graph * graph;
    //std::unordered_map<Node *, double> dist; USED FOR TESTING
    std::unordered_map<Node *, Node *> path;
    //std::unordered_map<Node*, bool> visited;
    void setup();
public:
    NodeToAll(Graph * g);
    std::unordered_map<Node *, double> dist;
    std::unordered_map<Node*, bool> visited;
    void dijkstra(Node* node);
};


#endif //VACCINEROUTER_NODETOALL_H
