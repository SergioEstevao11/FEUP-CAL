//
// Created by rodrigo on 19/05/2021.
//

#include "Manager.h"
#include "graph/GraphReader.h"
#include "algorithms/BiDijkstra.h"
#include "algorithms/AStar.h"
#include "algorithms/ClarkeWright.h"

using namespace std;

Manager::Manager(string nodes, string edges, string depots, string clients) {
    GraphReader graphReader(&graph);
    graphReader.readNodes(nodes);
    graphReader.readEdges(edges);
    poi.setGraph(&graph);
    poi.readDepots(depots);
    poi.readClients(clients);
}

double Manager::getPath(char algorithm, unsigned int &time, vector<Edge *> &path,
                                                        unsigned int source, unsigned int dest) {
    if(algorithm == 'd'){
        Dijkstra dijkstra(&graph);
        dijkstra.run(graph.getNode(source));
        return dijkstra.getPath(graph.getNode(source), graph.getNode(dest), path);
    }
    else if (algorithm == 'b') {
        BiDijkstra biDijkstra(&graph);
        double dist = biDijkstra.run(graph.getNode(source), graph.getNode(dest));
        path = biDijkstra.getPath(graph.getNode(source), graph.getNode(dest));
        return dist;
    }
    else if (algorithm == 'a') {
        AStar aStar(&graph);
        double dist = aStar.run(graph.getNode(source), graph.getNode(dest));
        path = aStar.getPath(graph.getNode(source), graph.getNode(dest));
        return dist;
    }
    return Graph::INF;
}

void Manager::getPOI(vector<Node *> &depots, unordered_map<Node *, double> &clients) {
    depots = poi.getDepots();
    clients = poi.getClients();
}

void Manager::getTrace(char algorithm, vector<Edge *> &forward, vector<Edge *> &backward,
                                                                unsigned int source, unsigned int dest) {
    if(algorithm == 'd'){
        Dijkstra dijkstra(&graph);
        dijkstra.run(graph.getNode(source));
        forward = dijkstra.getTrace();
    }
    else if (algorithm == 'b') {
        BiDijkstra biDijkstra(&graph);
        biDijkstra.run(graph.getNode(source), graph.getNode(dest));
        forward = biDijkstra.getTraceForward();
        backward = biDijkstra.getTraceBackward();
    }
    else if (algorithm == 'a') {
        AStar aStar(&graph);
        aStar.run(graph.getNode(source), graph.getNode(dest));
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
