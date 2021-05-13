#include <iostream>

#include "graph/GraphReader.h"
#include "algorithms/Dijkstra.h"
#include "algorithms/BiDijkstra.h"
#include "algorithms/Kosaraju.h"
#include "algorithms/Tarjan.h"
#include "algorithms/AStar.h"
#include "GraphDisplayer.h"

using namespace std;

int main() {
    Graph g;
    GraphReader gReader(&g);

    std::string nodeS = "../maps/porto_full_nodes_xy.txt";
    std::string edgeS = "../maps/porto_full_edges.txt";
    gReader.readNodes(nodeS);
    gReader.readEdges(edgeS);

    /*Dijkstra dijk(&g);
    Dijkstra ast(&g);
    dijk.dijkstra(g.getNode(50));
    std::cout << "unidirected dijkstra: " << dijk.dist[g.getNode(56)] << std::endl;
    ast.aStar(g.getNode(50));
    std::cout << "unidirected aStar: " << ast.dist[g.getNode(56)] << std::endl;*/
    /*GraphDisplayer gd(&g);
    gd.display();*/
    BiDijkstra twodijk(&g);
    AStar as(&g);
    int i = 0;
    int j = 0;
    for(auto & u : g.nodes){
        j++;
        if(j == 31) break;
        for(auto & v : g.nodes){
            i++;
            if(i == j*30) break;
            if(u != v){
                if(abs(twodijk.run(u,v) - as.run(u,v)) > 1e-5){
                    cout << "DIFF" << endl;
                    cout << u->getId() << " " << v->getId() << endl;
                    cout << twodijk.run(u,v) << " " <<  as.run(u,v) << endl;
                }
            }
        }
    }
    cout << i << endl;
    /*Kosaraju kos(&g);
    kos.run();
    Tarjan tar(&g);
    tar.run();

    for(auto &u : kos.SCC){
        if(u.second->getId() != tar.SCC[u.first]->getId()){
            cout << "DIFF\n";
        }
            //cout << u.first->getId() << " - " << u.second->getId() << endl;
    }*/
}
