//
// Created by rodrigo on 05/05/2021.
//
#include "Node.h"

#include <cmath>

Node::Node(unsigned int id, double x, double y) {
    this->id = id;
    this->x = x;
    this->y = y;
}

unsigned int Node::getId() {
    return id;
}

double Node::getX(){
    return x;
}

double Node::getY(){
    return y;
}

double Node::dist(Node *node) {
    return sqrt(pow(x - node->getX(),2) + pow(y - node->getY(),2));
}
