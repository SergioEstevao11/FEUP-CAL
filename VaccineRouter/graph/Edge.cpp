//
// Created by rodrigo on 05/05/2021.
//
#include "Edge.h"
#include <math.h>

Edge::Edge(Node * begin, Node* end){
    this->begin = begin;
    this->end = end;
    this->weight = sqrt(pow(begin->getX() - end->getX(),2) + pow(begin->getY() - end->getY(),2));
}

Node * Edge::getBegin(){
    return begin;
}
Node * Edge::getEnd(){
    return end;
}
double Edge::getWeight(){
    return weight;
}