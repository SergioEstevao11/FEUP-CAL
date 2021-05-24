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
    std::unordered_map<Node *, double> dist;
    std::unordered_map<Node *, Edge *> path;
    std::unordered_map<Node*, bool> visited;
    std::vector<Edge*> trace;
    unsigned int executionTime;

    /**
     * @brief Assigns the default values
     */
    void setup();
public:

    /**
     * @brief Dijkstra constructor
     *
     * @param g Pointer to the graph to be used
     */
    Dijkstra(Graph * g);

    /**
     * @brief Executes the algorithm
     *
     * @param node Pointer to the node from which the weight is calculated
     */
    void run(Node* node);

    /**
     * @brief   Retrieves the path between the nodes source and dist
     *
     * @param source source node
     * @param dist dist node
     * @return Vector of edge pointers that represent the requested path
     */
    double getPath(Node * source, Node * dist, std::vector<Edge *> &retPath);

    /**
     * @brief   Retrieves all the edges traversed by the last execution of the algorithm
     *
     * @return  Vector of edge pointers that represent the requested trace
     */
    std::vector<Edge*> getTrace();

    /**
     *@brief    Retrieves the time it took complete the previous execution of the algorithm
     *
     * @return  Time in milliseconds
     */
    unsigned int getExecutionTime() const;
};


#endif //VACCINEROUTER_DIJKSTRA_H
