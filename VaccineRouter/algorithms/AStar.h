//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_ASTAR_H
#define VACCINEROUTER_ASTAR_H


#include "../graph/Graph.h"

#include <vector>

class AStar {
private:
    Graph * graph;
    std::unordered_map<Node *, double> dist;
    std::unordered_map<Node *, Edge *> path;
    std::unordered_map<Node*, bool> visited;
    std::unordered_map<Node *, double> heuristic;
    std::vector<Edge*> trace;
    void setup(Node * dest);

public:
    AStar(Graph * g);
    double run(Node* orig, Node* dest);
    std::vector<Edge *> getPath(Node * source, Node * dist);
    std::vector<Edge*> getTrace(){return trace;};
};


#endif //VACCINEROUTER_ASTAR_H
