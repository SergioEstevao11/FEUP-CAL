//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_ASTAR_H
#define VACCINEROUTER_ASTAR_H


#include "../graph/Graph.h"

class AStar {
private:
    Graph * graph;
    //std::unordered_map<Node *, double> dist; USED FOR TESTING
    std::unordered_map<Node *, Node *> path;
    std::unordered_map<Node*, bool> visited;
    std::unordered_map<Node *, double> heuristic;
    void setup(Node * dest);

public:
    AStar(Graph * g);
    std::unordered_map<Node *, double> dist;
    double run(Node* orig, Node* dest);

};


#endif //VACCINEROUTER_ASTAR_H
