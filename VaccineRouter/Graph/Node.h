//
// Created by rodrigo on 05/05/2021.
//

#ifndef VACCINEROUTER_NODE_H
#define VACCINEROUTER_NODE_H
class Node{
private:
    unsigned int id;
    long double x;
    long double y;
public:
    unsigned int getId();
    long double getX();
    long double getY();
};
#endif //VACCINEROUTER_NODE_H
