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
    Route(Node* node, double weight, double capacity, double maxCapacity, double maxWeight);
    double getCapacity();
    double getWeight();
    std::vector<Node*> getNodes();
    bool isFirstNode(Node * node);
    bool isLastNode(Node * node);
    bool addRoute(Route * route, double saving);
};


#endif //VACCINEROUTER_ROUTE_H
