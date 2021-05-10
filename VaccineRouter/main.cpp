#include <iostream>

#include "Graph/GraphReader.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/BiDirectionalDijkstra.h"

using namespace std;

int main() {
    Graph g;
    GraphReader gReader(&g);

    std::string nodeS = "../maps/porto_full_nodes_xy.txt";
    std::string edgeS = "../maps/porto_full_edges.txt";
    gReader.readNodes(nodeS);
    gReader.readEdges(edgeS);

    Dijkstra dijk(&g);
    dijk.run(g.getNode(1));
    std::cout << "unidirected: " << dijk.dist[g.getNode(9)] << std::endl;

    BiDirectionalDijkstra twodijk(&g);
    cout << "bidirected: " << twodijk.run(g.getNode(1), g.getNode(9)) << endl;
}
