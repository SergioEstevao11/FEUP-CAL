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
    Graph * graph;
public:
    /**
     * Initializes the graph where the nodes and edges will be inserted
     * @param graph
     */
    GraphReader(Graph * graph);
    /**
     * Reads the nodes from a file
     * @param filename
     */
    void readNodes(std::string &filename);
    /**
     * Reads the edges from a file
     * @param filename
     */
    void readEdges(std::string &filename);

};


#endif //VACCINEROUTER_GRAPHREADER_H
