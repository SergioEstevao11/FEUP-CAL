#ifndef VACCINEROUTER_POI_H
#define VACCINEROUTER_POI_H

#include <vector>
#include <unordered_map>

#include "../graph/Graph.h"
#include "../algorithms/Dijkstra.h"

class POI {
private:
    Graph *graph;
    std::vector<Node *> depots;
    std::unordered_map<Node *, double> clients;
    std::unordered_map<Node *, Dijkstra *> dijkstra;
    std::unordered_map<Node *, std::unordered_map<Node *, double> > association;
    std::unordered_map<Node *, std::unordered_map<Node *, std::unordered_map<Node *, double>>> costFunctions;
    std::unordered_map<Node *, std::unordered_map<Node *, std::unordered_map<Node *, std::vector<Edge *>>>> paths;

    /**
     * @brief Associates each client to a depot
     */
    void associate();

    /**
     * @brief Calculates the cost of going from a node to another
     */
    void calculateCostFunctions();

public:
    ~POI();

    /**
     * @brief Sets the graph to the graph provided as argument
     * @param graph
     */
    void setGraph(Graph *graph);

    /**
     * @brief Reads the depots from a file and stores them
     * @param filename
     */
    void readDepots(std::string &filename);

    /**
     * Reads the clients from a file and stores them
     * @param filename
     */
    void readClients(std::string &filename);

    /**
     * Applies dijkstra on all the points of interest and then associates each client to a depot
     */
    void preProcess();

    /**
     * @brief Retrieves the depots
     * @return depots
     */
    std::vector<Node *> &getDepots();

    /**
     * @brief Retrieves the client's associated to the depot provided as argument
     * @param depot
     * @return client's associated to depot
     */
    std::unordered_map<Node *, double> &getAssociatedClients(Node * depot);

    /**
     * @brief Retrieves the clients
     * @return clients
     */
    std::unordered_map<Node *, double> &getClients();

    /**
    * @brief Retrieves the costs of the vehicles' path associated with the parsed depot
    * @param depot Pointer to the depot
    * @return Unordered map containing all the costs
    */

    std::unordered_map<Node *, std::unordered_map<Node *, double>> &getCostFunction(Node *depot);

    /**
    * @brief Retrieves the paths of vehicles that are associated with the parsed depot
    * @param depot Pointer to the depot
    * @return Unordered map containing all the paths
    */
    std::unordered_map<Node *, std::unordered_map<Node *, std::vector<Edge *>>> &getPaths(Node *depot);
};


#endif //VACCINEROUTER_POI_H
