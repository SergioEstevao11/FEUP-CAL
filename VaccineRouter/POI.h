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
    ~POI();
    void setGraph(Graph * graph);
    void readDepots(std::string &filename);
    void readClients(std::string &filename);
    void preProcess();
    std::vector<Node*> &getDepots(){return depots;};
    std::unordered_map<Node*, double> &getClients(){return clients;};

    std::unordered_map<Node *, double> &getAssociatedClients(Node * depot);

    std::unordered_map<Node *, std::unordered_map<Node *, double>> &getCostFunction(Node * node);
    std::unordered_map<Node *, std::unordered_map<Node *, std::vector<Edge*>>> &getPaths(Node * node);
};


#endif //VACCINEROUTER_POI_H
