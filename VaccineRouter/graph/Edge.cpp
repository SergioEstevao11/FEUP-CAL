//
// Created by rodrigo on 05/05/2021.
//
#include "Edge.h"

Edge::Edge(Node * begin, Node* end){
    this->begin = begin;
    this->end = end;
    this->weight = begin->dist(end);
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