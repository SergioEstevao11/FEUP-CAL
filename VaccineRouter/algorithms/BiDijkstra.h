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
    Node * midPoint;
    std::unordered_map<Node *, double> distForward;
    std::unordered_map<Node *, double> distBackward;
    std::unordered_map<Node *, Edge *> pathf;
    std::unordered_map<Node *, Edge *> pathb;
    std::unordered_map<Node*, bool> visitedForward;
    std::unordered_map<Node*, bool> visitedBackward;
    std::vector<Edge*> traceForward;
    std::vector<Edge*> traceBackward;
    unsigned int executionTime;

    /**
     * @brief Assigns the default values
     */
    void setup();
public:

    /**
     * @brief Bidirectional Dijkstra constructor
     *
     * @param g Pointer to the graph to be used
     */
    BiDijkstra(Graph * graph);


    /**
     * @brief Executes the algorithm
     *
     * @param orig Pointer to starting node
     * @param dest Pointer to destination node
     * @return distance of the shortest path found, Graph::INF if no path connecting the two nodes was found
     */
    double run(Node * orig, Node* dest);

    /**
     * @brief   Retrieves the path between the nodes source and dist
     *
     * @param source Pointer to the source node
     * @param dist Pointer to the destination node
     * @return Vector of edge pointers that represent the requested path
     */
    std::vector<Edge *> getPath(Node * source, Node * dist);

    /**
     * @brief   Retrieves all the edges traversed by the forward traversal of last execution of the algorithm
     *
     * @return  Vector of edge pointers that represent the requested trace
     */
    std::vector<Edge*> &getTraceForward(){return traceForward;};

    /**
     * @brief   Retrieves all the edges traversed by the backward traversal of last execution of the algorithm
     *
     * @return  Vector of edge pointers that represent the requested trace
     */
    std::vector<Edge*> &getTraceBackward(){return traceBackward;};

    /**
     *@brief    Retrieves the time it took complete the previous execution of the algorithm
     *
     * @return  Time in milliseconds
     */
    unsigned int getExecutionTime() const;
};


#endif //VACCINEROUTER_BIDIJKSTRA_H
