//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_BIDIJKSTRA_H
#define VACCINEROUTER_BIDIJKSTRA_H


#include "../graph/Graph.h"

#include <vector>

class BiDijkstra {
private:
    Graph * graph;
    Node * midPoint;
    std::unordered_map<Node *, double> distForward;
    std::unordered_map<Node *, double> distBackward;
    std::unordered_map<Node *, Edge *> pathf;
    std::unordered_map<Node *, Edge *> pathb;
    std::unordered_map<Node*, bool> visitedForward;
    std::unordered_map<Node*, bool> visitedBackward;
    std::vector<Edge*> traceForward;
    std::vector<Edge*> traceBackward;
    unsigned int executionTime;
    void setup();
public:
    BiDijkstra(Graph * graph);
    double run(Node * orig, Node* dest);
    std::vector<Edge *> getPath(Node * source, Node * dist);
    std::vector<Edge*> &getTraceForward(){return traceForward;};
    std::vector<Edge*> &getTraceBackward(){return traceBackward;};
    unsigned int getExecutionTime();
};


#endif //VACCINEROUTER_BIDIJKSTRA_H
