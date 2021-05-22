//
// Created by rodrigo on 19/05/2021.
//

#include "Manager.h"
#include "graph/GraphReader.h"
#include "algorithms/BiDijkstra.h"
#include "algorithms/AStar.h"
#include "algorithms/ClarkeWright.h"
#include "algorithms/Kosaraju.h"
#include "algorithms/Tarjan.h"

using namespace std;

Manager::Manager(string nodes, string edges, string depots, string clients) {
    GraphReader graphReader(&graph);
    graphReader.readNodes(nodes);
    graphReader.readEdges(edges);
    poi.setGraph(&graph);
    poi.readDepots(depots);
    poi.readClients(clients);
}

double Manager::getPath(int algorithm, unsigned int &time, vector<Edge *> &path,
                                                        Node * source, Node * dest) {
    if(algorithm == 1){
        Dijkstra dijkstra(&graph);
        dijkstra.run(source);
        return dijkstra.getPath(source, dest, path);
    }
    else if (algorithm == 2) {
        BiDijkstra biDijkstra(&graph);
        double dist = biDijkstra.run(source, dest);
        path = biDijkstra.getPath(source, dest);
        return dist;
    }
    else if (algorithm == 3) {
        AStar aStar(&graph);
        double dist = aStar.run(source, dest);
        path = aStar.getPath(source, dest);
        return dist;
    }
    return Graph::INF;
}

void Manager::getPOI(vector<Node *> &depots, unordered_map<Node *, double> &clients) {
    depots = poi.getDepots();
    clients = poi.getClients();
}

void Manager::getTrace(int algorithm, vector<Edge *> &forward, vector<Edge *> &backward,
                                                                Node * source, Node * dest) {
    if(algorithm == 1){
        Dijkstra dijkstra(&graph);
        dijkstra.run(source);
        forward = dijkstra.getTrace();
    }
    else if (algorithm == 2) {
        BiDijkstra biDijkstra(&graph);
        biDijkstra.run(source,dest);
        forward = biDijkstra.getTraceForward();
        backward = biDijkstra.getTraceBackward();
    }
    else if (algorithm == 3) {
        AStar aStar(&graph);
        aStar.run(source, dest);
        forward =aStar.getTrace();
    }
}

void Manager::getRoutes(vector<vector<vector<Edge *>>> &routes) {
    poi.preProcess();
    vector<Node*> depots = poi.getDepots();
    for(auto & depot : depots){
        unordered_map<Node*,unordered_map<Node*, vector<Edge*>>> paths = poi.getPaths(depot);
        ClarkeWright clarkeWright(depot, poi.getAssociatedClients(depot),
                                            poi.getCostFunction(depot), 10000, 100);
        clarkeWright.run();
        vector<vector<Edge*>> depotRoutes;
        unordered_set<Route*> ans = clarkeWright.getRoutes();
        for(auto & route : ans){
            vector<Edge*> depotRoute;
            vector<Node*> nodes = route->getNodes();
            depotRoute.insert(depotRoute.end(), paths[depot][nodes[0]].begin(), paths[depot][nodes[0]].end());
            for(int i = 0; i < nodes.size() - 1; i++){
                depotRoute.insert(depotRoute.end(), paths[nodes[i]][nodes[i+1]].begin(),
                                                                                paths[nodes[i]][nodes[i+1]].end());
            }
            depotRoute.insert(depotRoute.end(), paths[nodes[nodes.size()-1]][depot].begin(),
                                                                        paths[nodes[nodes.size()-1]][depot].end());
            depotRoutes.push_back(depotRoute);
        }
        routes.push_back(depotRoutes);
    }
}

Graph *Manager::getGraph() {
    return &graph;
}

void Manager::getSCC(int algorithm, std::unordered_map<Node *, Node *> &scc) {
    if(algorithm == 1){
        Kosaraju kosaraju(&graph);
        kosaraju.run();
        scc = kosaraju.getSCC();
    } else if(algorithm == 2){
        Tarjan tarjan(&graph);
        tarjan.run();
        scc = tarjan.getSCC();
    }
}

