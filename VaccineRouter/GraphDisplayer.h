//
// Created by rodrigo on 13/05/2021.
//

#ifndef VACCINEROUTER_GRAPHDISPLAYER_H
#define VACCINEROUTER_GRAPHDISPLAYER_H


#include "graph/Graph.h"

class GraphDisplayer {
    Graph *graph;
public:
    GraphDisplayer(Graph * graph);
    void display();
};


#endif //VACCINEROUTER_GRAPHDISPLAYER_H
