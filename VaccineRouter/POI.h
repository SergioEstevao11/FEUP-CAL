//
// Created by rodrigo on 14/05/2021.
//

#ifndef VACCINEROUTER_POI_H
#define VACCINEROUTER_POI_H

#include <vector>
#include <unordered_map>

#include "graph/Graph.h"
#include "algorithms/Dijkstra.h"

class POI {
private:
    Graph *graph;
    std::vector<Node*> depots;
    std::unordered_map<Node*, double> clients;
    std::unordered_map<Node*, Dijkstra *> dijkstra;
    std::unordered_map<Node*, std::unordered_map<Node*, double> >association;
    std::unordered_map<Node*, std::unordered_map<Node *, std::unordered_map<Node*,double>>> costFunctions;
    std::unordered_map<Node*, std::unordered_map<Node *, std::unordered_map<Node*,std::vector<Edge*>>>> paths;
    void associate();
    void calculateCostFunctions();
public:
    POI(Graph * graph);
    ~POI();
    void readDepots(std::string filename);
    void readClients(std::string filename);
    void preProcess();
    void printteste();
    std::vector<Node*> &getDepots(){return depots;};
    std::unordered_map<Node*, double> &getClients(){return clients;};
};


#endif //VACCINEROUTER_POI_H
