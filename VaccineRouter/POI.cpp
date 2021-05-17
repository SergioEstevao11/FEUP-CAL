//
// Created by rodrigo on 14/05/2021.
//

#include "POI.h"
#include "algorithms/BiDijkstra.h"
#include "algorithms/AStar.h"
#include "algorithms/ClarkeWright.h"

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

POI::POI(Graph *graph) {
    this->graph = graph;
}

void POI::readDepots(std::string filename) {
    ifstream inFile;
    inFile.open(filename);

    if(!inFile.is_open()){
        cout << "Unable to open File" << endl;
    } else {
        unsigned int numDepots;
        inFile >> numDepots;
        inFile.ignore();

        for(unsigned int i = 0; i < numDepots; i++){
            unsigned int id;
            string tmp;

            getline(inFile, tmp);
            istringstream iss(tmp);

            iss >> id;

            depots.push_back(graph->getNode(id));
        }
    }
}

void POI::readClients(string filename) {
    ifstream inFile;
    inFile.open(filename);

    if(!inFile.is_open()){
        cout << "Unable to open File" << endl;
    } else {
        unsigned int numClients;
        inFile >> numClients;
        inFile.ignore();

        for(unsigned int i = 0; i < numClients; i++){
            unsigned int id;
            double demand;
            char dum;
            string tmp;

            getline(inFile, tmp);
            istringstream iss(tmp);

            iss >> id
                >> dum >> demand;

            clients[graph->getNode(id)] = demand;
        }
    }
}

void POI::associate() {
    for(auto & c : clients) {
        Node *client = c.first;
        Node *depot;
        double minDistfront = Graph::INF;
        double minDistback = Graph::INF;
        vector<Edge *> minPathfront;
        vector<Edge *> minPathback;
        vector<Edge *> pathf;
        vector<Edge *> pathb;
        for (auto &d : depots) {
            double distf = dijkstra[d]->getPath(d, client, pathf);
            double distb = dijkstra[client]->getPath(client, d, pathb);
            if (distb + distf < minDistback + minDistfront) {
                minDistfront = distf;
                minDistback = distb;
                minPathfront = pathf;
                minPathback = pathb;
                depot = d;
            }
        }
        association[depot].insert(c);
        costFunctions[depot][depot][client] = minDistfront;
        costFunctions[depot][client][depot] = minDistback;
        paths[depot][depot][client] = minPathfront;
        paths[depot][client][depot] = minPathback;
    }
}

void POI::calculateCostFunctions() {
    for(auto & d : depots) {
        for (auto &c1 : association[d]) {
            for (auto &c2 : association[d]) {
                Node *client1 = c1.first;
                Node *client2 = c2.first;
                vector<Edge *> pathFront;
                vector<Edge *> pathBack;
                if (c1.first != c2.first) {
                    costFunctions[d][client1][client2] = dijkstra[client1]->getPath(client1, client2, pathFront);
                    paths[d][client1][client2] = pathFront;
                    costFunctions[d][client1][client2] = dijkstra[client2]->getPath(client2, client1, pathBack);
                    paths[d][client1][client2] = pathBack;
                }
            }
        }
    }
}

void POI::printteste() {
    for(auto & d : depots){
        cout << d->getId() << endl;
        for(auto &c : association[d]){
            cout << c.first->getId() << " - " << c.second << endl;
        }
    }
}

void POI::preProcess() {
    for(auto & d : depots){
        Dijkstra * dk = new Dijkstra(graph);
        dk->run(d);
        dijkstra[d] = dk;
    }

    for(auto & c : clients){
        Dijkstra * dk = new Dijkstra(graph);
        dk->run(c.first);
        dijkstra[c.first] = dk;
    }

    associate();
    calculateCostFunctions();
}

POI::~POI() {
    for(auto & dj : dijkstra){
        delete dj.second;
    }
}

std::vector<Edge *> POI::testiguess() {
    vector<Edge*> pp;
    for(auto & depot : depots){
        ClarkeWright cw(depot, association[depot], costFunctions[depot], 100000, 100);
        cw.run();
        unordered_set<Route*> ans = cw.getRoutes();
        cout << ans.size() << endl;
        for(auto & v : ans){
            vector<Node*> aa = v->getNodes();
            pp.insert(pp.end(), paths[depot][depot][aa[0]].begin(), paths[depot][depot][aa[0]].end());
            for(int i = 0; i < aa.size() - 1; i++){
                pp.insert(pp.end(), paths[depot][aa[i]][aa[i+1]].begin(), paths[depot][aa[i]][aa[i+1]].end());
            }
            pp.insert(pp.end(), paths[depot][aa[aa.size() - 1]][depot].begin(), paths[depot][aa[aa.size() - 1]][depot].end());
        }
    }
    return pp;
}
