//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_TARJAN_H
#define VACCINEROUTER_TARJAN_H


#include <stack>

#include "../graph/Graph.h"

class Tarjan {
private:
    Graph * graph;
    std::unordered_map<Node*,Node*> SCC;
    std::unordered_map<Node*,int> id;
    std::unordered_map<Node*,int> lowLink;
    std::unordered_map<Node*,bool> onStack;
    std::stack<Node*> stack;
    int index;
    unsigned int executionTime;
    /**
     * @brief Initializes data members of the graph to be used in the algorithm
     */
    void setup();
    /**
     * @brief Performs a DFS and assigns the SCC
     * @param node Pointer to the node to be searched
     */
    void strongComponent(Node * node);
public:
    /**
     * @brief Constructor with the graph that's going to be used in the algorithm
     * @param graph Graph to be used in the algorithm
     */
    explicit Tarjan(Graph * graph);
    /**
     * @brief Executes the algorithm
     */
    void run();
    /**
     * @brief Retrieves a map of the strongly connected components
     * @return map of the strongly connected components
     */
    std::unordered_map<Node*,Node*>& getSCC();
    /**
     * @brief Retrieves the execution time of the algorithm
     * @return Execution time
     */
    unsigned int getExecutionTime() const;
};


#endif //VACCINEROUTER_TARJAN_H
