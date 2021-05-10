//
// Created by rodrigo on 05/05/2021.
//
#include "Node.h"

Node::Node(unsigned int id, double x, double y) {
    this->id = id;
    this->x = x;
    this->y = y;
}

unsigned int Node::getId() {
    return id;
}

long double Node::getX(){
    return x;
}

long double Node::getY(){
    return y;
}
