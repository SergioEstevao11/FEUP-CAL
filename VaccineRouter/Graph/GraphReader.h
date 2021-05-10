//
// Created by rodrigo on 10/05/2021.
//

#ifndef VACCINEROUTER_GRAPHREADER_H
#define VACCINEROUTER_GRAPHREADER_H

#include "unordered_map"
#include "Node.h"
#include "Graph.h"

class GraphReader {
private:
    std::unordered_map<unsigned int, Node*> nodes;
    Graph * graph;
public:
    GraphReader(Graph * graph);
    void readNodes(std::string &filename);
    void readEdges(std::string &filename);

};


#endif //VACCINEROUTER_GRAPHREADER_H
