//
// Created by rodrigo on 05/05/2021.
//

#ifndef VACCINEROUTER_GRAPH_H
#define VACCINEROUTER_GRAPH_H

#include "Node.h"
#include "Edge.h"

#include <unordered_set>
#include <unordered_map>

class Graph{
private:
    std::unordered_set<Node*> nodes;
    std::unordered_map<Node*, std::unordered_set<Edge*>> adjList;
    bool nodeExists(Node * node);
    bool edgeExists(Edge * edge);
public:
    ~Graph();
    void addNode(Node * node);
    void addEdge(Edge * edge);
    std::unordered_set<Node*> getNodes() {return nodes;};

};
#endif //VACCINEROUTER_GRAPH_H
