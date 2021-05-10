#include <iostream>

#include "Graph/GraphReader.h"
#include "algorithms/NodeToAll.h"
#include "algorithms/NodeToNode.h"
#include "algorithms/Kosaraju.h"

using namespace std;

int main() {
    Graph g;
    GraphReader gReader(&g);

    std::string nodeS = "../maps/porto_strong_nodes_xy.txt";
    std::string edgeS = "../maps/porto_strong_edges.txt";
    gReader.readNodes(nodeS);
    gReader.readEdges(edgeS);

    NodeToAll dijk(&g);
    NodeToAll ast(&g);
    dijk.dijkstra(g.getNode(50));
    std::cout << "unidirected dijkstra: " << dijk.dist[g.getNode(56)] << std::endl;
    ast.aStar(g.getNode(50));
    std::cout << "unidirected aStar: " << ast.dist[g.getNode(56)] << std::endl;

    NodeToNode twodijk(&g);
    cout << "bidirected: " << twodijk.dijkstra(g.getNode(50), g.getNode(56)) << endl;
    cout << "bidirected: " << twodijk.dijkstra(g.getNode(56), g.getNode(50)) << endl;

    Kosaraju kos(&g);
    kos.run();
    /*for(auto &u : kos.SCC){
        cout << u.first->getId() << " - " << u.second->getId() << endl;
    }*/
}
