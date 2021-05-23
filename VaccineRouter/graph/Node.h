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
    /**
     * Initializes the id of a node and it's x and y coordinates
     */
    Node(unsigned int, double x, double y);
    /**
     * Retrieves the id
     * @return id
     */
    unsigned int getId();
    /**
     * Retrieves the x coordinate
     * @return x
     */
    double getX();
    /**
     * Retrieves the y coordinate
     * @return y
     */
    double getY();
    /**
     * Distance to the node passed as argument
     */
    double dist(Node * node);
};
#endif //VACCINEROUTER_NODE_H
