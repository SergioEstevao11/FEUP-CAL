//
// Created by rodrigo on 14/05/2021.
//

#ifndef VACCINEROUTER_ROUTE_H
#define VACCINEROUTER_ROUTE_H

#include <vector>

#include "../graph/Node.h"


class Route {
private:
    std::vector<Node*> nodes;
    double weight;
    double capacity;
    double maxWeight;
    double maxCapacity;
public:
    /**
     * @brief Route constructor
     *
     * @param node Beginning node
     * @param weight
     * @param capacity
     * @param maxCapacity
     * @param maxWeight
     */
    Route(Node* node, double weight, double capacity, double maxCapacity, double maxWeight);
    /**
     * @brief Retrieves the capacity
     * @return capacity
     */
    double getCapacity();
    /**
     * @brief Retrieves the weight
     * @return weight
     */
    double getWeight();
    /**
     * @brief Retrieves the route's nodes
     * @return Returns the Route's nodes
     */
    std::vector<Node*> getNodes();
    /**
     * @brief Checks if node is the first node of the route
     * @param node Node to be checked
     * @return True if node is the first node, false otherwise
     */
    bool isFirstNode(Node * node);
    /**
     * @brief Checks if node is the last node of the route
     * @param node Node to be checked
     * @return True if node is the last node, false otherwise
     */
    bool isLastNode(Node * node);
    /**
     * @brief Tries the connect to a new Route
     * @param route Route to be connected
     * @param saving Consequent savings that would come from the connection
     * @return True if the connection was successful, false otherwise
     */
    bool addRoute(Route * route, double saving);
};


#endif //VACCINEROUTER_ROUTE_H
