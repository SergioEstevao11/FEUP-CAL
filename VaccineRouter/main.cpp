#include <iostream>

#include "Graph/GraphReader.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/BiDirectionalDijkstra.h"

using namespace std;

int main() {
    Graph g;
    GraphReader gReader(&g);

    std::string nodeS = "../maps/porto_strong_nodes_xy.txt";
    std::string edgeS = "../maps/porto_strong_edges.txt";
    gReader.readNodes(nodeS);
    gReader.readEdges(edgeS);

    Dijkstra dijk(&g);
    dijk.run(g.getNode(1));
    std::cout << "unidirected: " << dijk.dist[g.getNode(11)] << std::endl;

    BiDirectionalDijkstra twodijk(&g);
    cout << "bidirected: " << twodijk.run(g.getNode(1), g.getNode(11)) << endl;
}
