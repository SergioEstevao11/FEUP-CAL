//
// Created by rodrigo on 14/05/2021.
//

#include "Route.h"

Route::Route(Node *node, double weight, double capacity, double maxCapacity, double maxWeight) {
    nodes.push_back(node);
    this->weight = weight;
    this->capacity = capacity;
    this->maxWeight = maxWeight;
    this->maxCapacity = maxCapacity;
}

bool Route::isFirstNode(Node *node) {
    return nodes[0] == node;
}

bool Route::isLastNode(Node *node) {
    return nodes[nodes.size()-1] == node;
}

bool Route::addRoute(Route *route, double saving) {
    if(route->getWeight() + weight - saving > maxWeight) return false;
    if(route->getCapacity() + capacity > maxCapacity) return false;

    nodes.insert(nodes.end(), route->getNodes().begin(), route->getNodes().end());
}

double Route::getCapacity() {
    return capacity;
}

double Route::getWeight() {
    return weight;
}

std::vector<Node *> Route::getNodes() {
    return nodes;
}
