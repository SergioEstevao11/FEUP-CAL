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
    unsigned int edgeCounter;
    std::unordered_map<unsigned int, Node*> nodeMap;
    std::unordered_map<unsigned int, Edge*> edgeMap;
    //std::unordered_set<Node*> nodes;
    std::unordered_map<Node*, std::unordered_set<Edge*>> adjList;
    std::unordered_map<Node*, std::unordered_set<Edge*>> predAdjList;
    bool nodeExists(Node * node);
    bool edgeExists(Edge * edge);

    friend class AStar;
    friend class BiAStar;
    friend class Dijkstra;
    friend class BiDijkstra;
    friend class Kosaraju;
    friend class Tarjan;

    //friend class GraphDisplayer;
public:
    Graph();
    std::unordered_set<Node*> nodes;
    ~Graph();
    const static double INF;
    void addNode(Node * node);
    void addEdge(Edge * edge);
    Node * getNode(unsigned int id);

    std::unordered_set<Node*> getNodes() {return nodes;};
    std::unordered_map<unsigned int, Edge*> getEdges() {return edgeMap;};

    //ONLY FOR TESTING
    unsigned numNodes() { return nodes.size();};
    unsigned numEdges() { int c = 0; for(auto & node : nodes){c += adjList[node].size();} return c;};
};
#endif //VACCINEROUTER_GRAPH_H
