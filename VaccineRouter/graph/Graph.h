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
    std::unordered_map<Edge*, unsigned int> edgeMap;
    std::unordered_map<Node*, std::unordered_set<Edge*>> adjList;
    std::unordered_map<Node*, std::unordered_set<Edge*>> predAdjList;
    /**
     * Checks if node exists on the graph
     * @param node
     * @return True if node exists, false otherwise
     */
    bool nodeExists(Node * node);
    /**
     * Checks if edge exists on the graph
     * @param edge
     * @return True if node exists, false otherwise
     */
    bool edgeExists(Edge * edge);

    friend class AStar;
    friend class Dijkstra;
    friend class BiDijkstra;
    friend class Kosaraju;
    friend class Tarjan;

    //friend class GraphDisplayer;
public:
    /**
     * Constructor without arguments
     */
    Graph();
    std::unordered_set<Node*> nodes;
    ~Graph();
    const static double INF;
    /**
     * Adds node to the graph
     * @param node
     */
    void addNode(Node * node);
    /**
     * Adds edge to the graph
     * @param edge
     */
    void addEdge(Edge * edge);
    /**
     * Retrieves the node with id equal to the one provided as argument
     * @param id
     * @return node *
     */
    Node * getNode(unsigned int id);
    /**
     * Retrieves the id of the edge provided as argument
     * @param edge
     * @return edge's id
     */
    unsigned int getEdgeId(Edge * edge);

    /**
     * @brief Retrieves the unordered set with the graph's nodes
     * @return Unordered set referred above
     */
    std::unordered_set<Node*> getNodes();

    /**
     * @brief Retrieves the unordered map with the graph's edges and respective ID
     * @return Unordered map referred above
     */
    std::unordered_map<Edge*, unsigned int> getEdges();
};
#endif //VACCINEROUTER_GRAPH_H
