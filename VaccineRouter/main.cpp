#include <iostream>

#include "graph/GraphReader.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/BiDijkstra.h"
#include "algorithms/Kosaraju.h"
#include "algorithms/Tarjan.h"
#include "algorithms/AStar.h"
#include "GraphDisplayer.h"
#include "menu/menuInterface.h"
#include "POI.h"

using namespace std;

int main() {
    Graph g;
    GraphReader gReader(&g);

    std::string nodeS = "../maps/porto_full_nodes_xy.txt";
    std::string edgeS = "../maps/porto_full_edges.txt";
    gReader.readNodes(nodeS);
    gReader.readEdges(edgeS);

    POI poi(&g);
    poi.readDepots("../maps/depots.txt");
    poi.readClients("../maps/clients.txt");
    poi.associate();

    GraphDisplayer gd(&g);
    gd.highlightPOI(poi.getClients(), poi.getDepots());
    gd.display();
    //poi.printteste();
    /*Dijkstra dijk(&g);
    Dijkstra ast(&g);
    dijk.dijkstra(g.getNode(50));
    std::cout << "unidirected dijkstra: " << dijk.dist[g.getNode(56)] << std::endl;
    ast.aStar(g.getNode(50));
    std::cout << "unidirected aStar: " << ast.dist[g.getNode(56)] << std::endl;*/
    /*GraphDisplayer gd(&g);

    //gd.SetDefaultColor();

    menuInterface menu(&gd);
    menu.mainMenuHandler();*/

}
