//
// Created by rodrigo on 05/05/2021.
//

#ifndef VACCINEROUTER_NODE_H
#define VACCINEROUTER_NODE_H
class Node{
private:
    unsigned int id;
    double x;
    double y;
public:
    Node(unsigned int, double x, double y);
    unsigned int getId();
    double getX();
    double getY();
    double dist(Node * node);
};
#endif //VACCINEROUTER_NODE_H
