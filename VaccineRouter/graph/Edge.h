//
// Created by rodrigo on 05/05/2021.
//
#ifndef VACCINEROUTER_EDGE_H
#define VACCINEROUTER_EDGE_H

#include "Node.h"

class Edge{
private:
    Node * begin;
    Node * end;
    double weight;
public:
    /**
     * Initializes the beginning and end node of the edge
     * @param begin beginning node
     * @param end finishing node
     */
    Edge(Node * begin, Node* end);
    Node * getBegin();
    Node * getEnd();
    /**
     * Retrieves the weight of the edge
     * @return weight
     */
    double getWeight();
};
#endif //VACCINEROUTER_EDGE_H
