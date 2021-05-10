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
    Edge(Node * begin, Node* end);
    Node * getBegin();
    Node * getEnd();
    double getWeight();
};
#endif //VACCINEROUTER_EDGE_H
