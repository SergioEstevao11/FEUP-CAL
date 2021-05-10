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
    dijk.run(g.getNode(50));
    std::cout << "unidirected: " << dijk.dist[g.getNode(56)] << std::endl;

    BiDirectionalDijkstra twodijk(&g);
    cout << "bidirected: " << twodijk.run(g.getNode(50), g.getNode(56)) << endl;
    cout << "bidirected: " << twodijk.run(g.getNode(56), g.getNode(50)) << endl;
}
