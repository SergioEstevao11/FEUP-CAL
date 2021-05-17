//
// Created by rodrigo on 14/05/2021.
//

#include "POI.h"
#include "algorithms/BiDijkstra.h"

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
    BiDijkstra bi(graph);
    for(auto &c : clients){
        Node * depot;
        Node * client = c.first;
        double minDistfront = Graph::INF;
        double minDistback = Graph::INF;
        vector<Edge*> minPathfront;
        vector<Edge*> minPathback;
        for(auto & d : depots){
            double distf = bi.run(d,client);
            vector<Edge*> pathf = bi.getPath(d,client);
            double distb = bi.run(client, d);
            vector<Edge*> pathb = bi.getPath(client, d);
            if(distb + distf < minDistback + minDistfront){
                minDistfront = distf;
                minDistback = distb;
                vector<Edge*> minPathfront = pathf;
                vector<Edge*> minPathback = pathb;
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
    BiDijkstra bi(graph);

    for(auto & d : depots){
        for(auto & c1 : association[d]){
            for(auto & c2 : association[d]){
                Node * client1 = c1.first;
                Node * client2 = c2.first;
                if(c1.first != c2.first){
                    costFunctions[d][client1][client2] = bi.run(client1, client2);
                    paths[d][client1][client2]= bi.getPath(client1,client2);
                    costFunctions[d][client1][client2] = bi.run(client1, client2);
                    paths[d][client1][client2]= bi.getPath(client1,client2);
                }
            }
        }
    }
}

