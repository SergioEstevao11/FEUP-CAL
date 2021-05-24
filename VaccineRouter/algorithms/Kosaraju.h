//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_KOSARAJU_H
#define VACCINEROUTER_KOSARAJU_H


#include "../graph/Graph.h"

#include<stack>

class Kosaraju {
private:
    Graph * graph;
    std::unordered_map<Node*,Node*> SCC;
    std::unordered_map<Node*,bool> visited;
    std::stack<Node*> stack;
    unsigned int executionTime;
    /**
     * @brief Assigns the default values
     */
    void setup();

    /**
     * @brief Performs a depth first search
     *
     * @param node Pointer to the node to be searched
     */
    void DFSFirst(Node * node);

    /**
     * @brief Performs a depth first search and assigns the nodes to the respective SCC
     *
     * @param node Pointer to the node to be searched
     * @param component Respective SCC
     */
    void DFSAssign(Node * node, Node * component);
public:

    /**
     * @brief Kosaraju constructor
     *
     * @param g Pointer to the graph to be used
     */
    explicit Kosaraju(Graph * graph);

    /**
     * @brief Executes the algorithm
     *
     */
    void run();

    /**
     * @brief   Retrieves an unordered map with the root of the Strongly Connected Component for each node
     *
     * @return  The unordered map of node pointers to node pointers
     */
    std::unordered_map<Node*,Node*> &getSCC();

    /**
     * @brief   Retrieves the time it took complete the previous execution of the algorithm
     *
     * @return  Time in milliseconds
     */
    unsigned int getExecutionTime() const;

};


#endif //VACCINEROUTER_KOSARAJU_H
