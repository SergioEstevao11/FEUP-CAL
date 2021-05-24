#include "Manager.h"

#include <chrono>
#include <fstream>

#include "graph/GraphReader.h"
#include "algorithms/BiDijkstra.h"
#include "algorithms/AStar.h"
#include "algorithms/ClarkeWright.h"
#include "algorithms/Kosaraju.h"
#include "algorithms/Tarjan.h"

typedef std::chrono::high_resolution_clock hrc;

using namespace std;

const double Manager::VANSPEED = 60000;

Manager::Manager(string &nodes, string &edges, string &depots, string &clients, string &data) {
    GraphReader graphReader(&graph);
    graphReader.readNodes(nodes);
    graphReader.readEdges(edges);
    poi.setGraph(&graph);
    poi.readDepots(depots);
    poi.readClients(clients);

    ifstream inFile;
    inFile.open(data);

    double maxTime;
    unsigned int maxQuantity;

    if(inFile.is_open()){
        inFile >> maxTime;
        inFile >> maxQuantity;
    }
}

double Manager::getPath(int algorithm, unsigned int &time, vector<Edge *> &path,
                                                        Node * source, Node * dest) {
    if(algorithm == 1){
        Dijkstra dijkstra(&graph);
        dijkstra.run(source);
        time = dijkstra.getExecutionTime();
        return dijkstra.getPath(source, dest, path);
    }
    else if (algorithm == 2) {
        BiDijkstra biDijkstra(&graph);
        double dist = biDijkstra.run(source, dest);
        time = biDijkstra.getExecutionTime();
        path = biDijkstra.getPath(source, dest);
        return dist;
    }
    else if (algorithm == 3) {
        AStar aStar(&graph);
        double dist = aStar.run(source, dest);
        time = aStar.getExecutionTime();
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

void Manager::getRoutes(vector<vector<vector<Edge *>>> &routes, unsigned int &time) {
    auto startTime = hrc::now();
    poi.preProcess();
    vector<Node*> depots = poi.getDepots();
    for(auto & depot : depots){
        unordered_map<Node*,unordered_map<Node*, vector<Edge*>>> paths = poi.getPaths(depot);
        ClarkeWright clarkeWright(depot, poi.getAssociatedClients(depot),
                                            poi.getCostFunction(depot), maxT*VANSPEED, maxQ);
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
    auto finishTime = hrc::now();
    time = chrono::duration_cast<std::chrono::milliseconds>(finishTime - startTime).count();
}

Graph *Manager::getGraph() {
    return &graph;
}

void Manager::getSCC(int algorithm, std::unordered_map<Node *, Node *> &scc, unsigned int &time) {
    if(algorithm == 1){
        Kosaraju kosaraju(&graph);
        kosaraju.run();
        time = kosaraju.getExecutionTime();
        scc = kosaraju.getSCC();
    } else if(algorithm == 2){
        Tarjan tarjan(&graph);
        tarjan.run();
        time = tarjan.getExecutionTime();
        scc = tarjan.getSCC();
    }
}

/*void Manager::sccStatistics(std::unordered_map<Node *, Node *> scc) { //está mal

    //unordered_map<Node *, int> visited;
    double avg = 0.0;
    int max = 0;
    int res;
    /*for(auto &n : scc){
        for (auto &n : scc) {
            visited[n.first] = false;
        }
        res = sccAvg(scc, n.first, visited);
        avg +=res;
        if(res > max){
            max = res;
        }
    }
    unordered_map<Node *, unsigned> Count;
    for(auto &n : scc){
        if(Count.find(n.second) == Count.end()){
            Count[n.second] = 1;
        }
        else{
            Count[n.second]++;
        }
    }
    for(auto &n : Count){
        avg += n.second;
        if(n.second > max){
            max = n.second;
        }
    }
    cout << "Total number of SCC: " << scc.size() << endl;
    cout << "Maximum SCC size: " << max << endl;
    cout << "Average SCC size: " << avg << endl;
}*/