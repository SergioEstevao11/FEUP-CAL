//
// Created by rodrigo on 14/05/2021.
//

#ifndef VACCINEROUTER_POI_H
#define VACCINEROUTER_POI_H

#include <vector>
#include <unordered_map>

#include "graph/Graph.h"

class POI {
private:
    Graph *graph;
    std::vector<Node*> depots;
    std::vector<Node*> clients;
    std::unordered_map<Node*, std::unordered_map<Node*, double> >association;
    std::unordered_map<Node*, std::unordered_map<Node *, std::unordered_map<Node*,double>>> costFunctions;
    std::unordered_map<Node*, std::unordered_map<Node *, std::unordered_map<Node*,std::vector<Node*>>>> paths;
public:
    void readDepots(std::string & filename);
    void readClients(std::string & filename);
    void associate();
};


#endif //VACCINEROUTER_POI_H
