#ifndef VACCINEROUTER_MANAGER_H
#define VACCINEROUTER_MANAGER_H


#include "POI.h"

class Manager {
private:
    POI poi;
    Graph graph;
public:
    Manager(std::string nodes, std::string edges, std::string depots, std::string clients);
    Graph * getGraph();
    double getPath(char algorithm, unsigned int &time, std::vector<Edge*> &path,
                                                    unsigned int source, unsigned int dest);
    void getPOI(std::vector<Node*> &depots, std::unordered_map<Node*,double> &clients);
    void getTrace(char algorithm, std::vector<Edge*> &forward, std::vector<Edge*> &backward,
                                                    unsigned int source, unsigned int dest);
    void getRoutes(std::vector<std::vector<std::vector<Edge*>>> &routes);
};


#endif //VACCINEROUTER_MANAGER_H
