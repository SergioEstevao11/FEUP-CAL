//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_ASTAR_H
#define VACCINEROUTER_ASTAR_H


#include "../graph/Graph.h"

#include <vector>


/**
 * @brief AStar algorithm
 *
 */

class AStar {
private:
    Graph * graph;
    std::unordered_map<Node *, double> dist;
    std::unordered_map<Node *, Edge *> path;
    std::unordered_map<Node*, bool> visited;
    std::unordered_map<Node *, double> heuristic;
    std::vector<Edge*> trace;
    unsigned int executionTime;

    /** @brief Assigns the default values
     *
     * @param dest Pointer to destination node
     */
    void setup(Node * dest);

public:
    /**
     * @brief AStar constructor
     *
     * @param g Pointer to the graph to be used
     */
    AStar(Graph * g);

    /**
     * @brief Executes the algorithm
     *
     * @param orig Pointer to starting node
     * @param dest Pointer to destination node
     * @return distance of the shortest path found, Graph::INF if no path connecting the two nodes was found
     */
    double run(Node* orig, Node* dest);

    /**
     * @brief   Retrieves the path between the nodes source and dist
     *
     * @param source source node
     * @param dist dist node
     * @return Vector of edge pointers that represent the requested path
     */
    std::vector<Edge *> getPath(Node * source, Node * dist);


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
    unsigned int getExecutionTime();
};


#endif //VACCINEROUTER_ASTAR_H
