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
    double getPath(int algorithm, unsigned int &time, std::vector<Edge*> &path,
                                                    Node * source, Node * dest);
    void getPOI(std::vector<Node*> &depots, std::unordered_map<Node*,double> &clients);
    void getTrace(int algorithm, std::vector<Edge*> &forward, std::vector<Edge*> &backward,
                                                    Node * source, Node * dest);
    void getRoutes(std::vector<std::vector<std::vector<Edge*>>> &routes);

    void getSCC(int algorithm, std::unordered_map<Node*, Node*> &scc);
};


#endif //VACCINEROUTER_MANAGER_H
