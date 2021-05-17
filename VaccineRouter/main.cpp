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

#include <chrono>
typedef std::chrono::high_resolution_clock hrc;

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
    GraphDisplayer gd(&g);
    auto start_time = hrc::now();
    poi.preProcess();
    auto end_time = hrc::now();
    cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << endl;
    poi.printteste();
    vector <Edge*> ans = poi.testiguess();
    gd.highlightPOI(poi.getClients(), poi.getDepots());
    gd.highlightPath(ans);
    gd.display();

    /*menuInterface menu(&gd);
    menu.mainMenuHandler();*/

}
