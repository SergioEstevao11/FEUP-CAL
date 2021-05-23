#ifndef VACCINEROUTER_MANAGER_H
#define VACCINEROUTER_MANAGER_H

#include "POI.h"

class Manager {
private:
    POI poi;
    Graph graph;
public:
    /**
     * @brief Initializes the graph with all the nodes, edges and the points of interest with all the depots and clients
     * @param nodes
     * @param edges
     * @param depots
     * @param clients
     */
    Manager(std::string nodes, std::string edges, std::string depots, std::string clients);
    /**
     * @brief Retrieves the graph
     * @return graph
     */
    Graph * getGraph();
    /**
     * @brief Retrieves the path from node source to dest according to the algorithm provided as argument
     * @param algorithm algorithm to be used
     * @param time execution time of the algorithm
     * @param path
     * @param source
     * @param dest
     * @return distance from node source to node dest
     */
    double getPath(int algorithm, unsigned int &time, std::vector<Edge*> &path,
                                                    Node * source, Node * dest);
    /**
     * @brief Retrieves the depots and clients of poi (points of interest)
     * @param depots
     * @param clients
     */
    void getPOI(std::vector<Node*> &depots, std::unordered_map<Node*,double> &clients);
    /**
     * @brief Retrieves all the edges where the algorithm provided as a argument passed
     * @param algorithm
     * @param forward
     * @param backward
     * @param source
     * @param dest
     */
    void getTrace(int algorithm, std::vector<Edge*> &forward, std::vector<Edge*> &backward,
                                                    Node * source, Node * dest);
    /**
     * @brief Retrieves all the routes
     * @param routes Container where all the routes will be saved to
     * @param time Variable that will hold the execution time
     */
    void getRoutes(std::vector<std::vector<std::vector<Edge*>>> &routes, unsigned int &time);

    /**
     * @brief Retrieves the strongly connected components using the algorithm provided as argument
     * @param algorithm
     * @param scc
     * @param time
     */
    void getSCC(int algorithm, std::unordered_map<Node*, Node*> &scc, unsigned int &time);
};


#endif //VACCINEROUTER_MANAGER_H
