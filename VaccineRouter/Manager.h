//
// Created by rodrigo on 19/05/2021.
//

#ifndef VACCINEROUTER_MANAGER_H
#define VACCINEROUTER_MANAGER_H


#include "POI.h"

class Manager {
private:
    POI poi;
    Graph graph;
public:
    Manager(std::string nodes, std::string edges, std::string depots, std::string clients);
    double getPath(char algorithm, unsigned int &time, std::vector<Edge*> path, unsigned int source, unsigned int dest);
    void getPOI(std::vector<Node*> &depots, std::unordered_map<Node*,double> &clients);
    double getTrace(char algorithm, std::vector<Edge*> forward, std::vector<Edge*> backward);
    void getRoutes(std::unordered_map<Node*, std::vector<Edge*>> routes);
};


#endif //VACCINEROUTER_MANAGER_H
