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

    /*POI poi(&g);
    poi.readDepots("../maps/depots.txt");
    poi.readClients("../maps/clients.txt");
    auto start_time = hrc::now();
    /*poi.associate();
    poi.calculateCostFunctions();
    auto start_time = hrc::now();*/
    /*poi.preProcess();
    auto end_time = hrc::now();
    cout << std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time).count() << endl;
    poi.printteste();*/
    GraphDisplayer gd(&g);
    AStar a(&g);
    Dijkstra d(&g);
    BiDijkstra bi(&g);
    Node * source = g.getNode(34460);
    Node * dest = g.getNode(29050);
    d.run(source);
    bi.run(source,dest);
    vector<Edge*> v = bi.getPath(source,dest);
            //cout << bi.run(source,dest) << " - " << a.run(source,dest) << " - " << d.getPath(source,dest,v) << endl;
    //gd.highlightPOI(poi.getClients(), poi.getDepots());
    gd.highlightPath(v);
    gd.display();
    //gd.setDefaultColor();
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
