#include <iostream>

#include "graph/GraphReader.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/BiDijkstra.h"
#include "algorithms/Kosaraju.h"
#include "algorithms/Tarjan.h"
#include "algorithms/AStar.h"
#include "GraphDisplayer.h"
#include "menu/menuInterface.h"
#include "Manager.h"

#include <chrono>
typedef std::chrono::high_resolution_clock hrc;

using namespace std;

int main() {
    std::string nodeS = "../maps/porto_full_nodes_xy.txt";
    std::string edgeS = "../maps/porto_full_edges.txt";
    std::string depotsS = "../maps/depots.txt";
    std::string clientsS = "../maps/clients.txt";
    Manager manager(nodeS, edgeS, depotsS, clientsS);
    vector<vector<vector<Edge*>>> routes;
    manager.getRoutes(routes);

    GraphDisplayer gd(manager.getGraph());
    vector<Node*> depots;
    unordered_map<Node*, double> clients;
    manager.getPOI(depots,clients);
    gd.highlightPOI(clients, depots);
    gd.highlightRoutes(routes);
    gd.display();
    /*menuInterface menu(&gd);
    menu.mainMenuHandler();*/

}
