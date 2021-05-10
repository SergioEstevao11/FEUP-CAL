#include <iostream>

#include "Graph/GraphReader.h"
#include <fstream>

int main() {
    Graph g;
    GraphReader gReader(&g);

    std::string nodeS = "..\\maps\\porto_strong_nodes_xy.txt";
    std::string edgeS = "..\\maps\\porto_strong_edges.txt";
    gReader.readNodes(nodeS);
    gReader.readEdges(edgeS);
    std::unordered_set<Node*> nd = g.getNodes();
    for(auto & n : nd){
        std::cout << n->getId() << std::endl;
    }
}
