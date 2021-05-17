//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_CLARKEWRIGHT_H
#define VACCINEROUTER_CLARKEWRIGHT_H


#include <unordered_set>
#include <unordered_map>
#include <vector>

#include "../graph/Node.h"
#include "Route.h"

struct Saving{
    double save;
    Node * from;
    Node * to;
};

bool cmp(Saving s1, Saving s2);

class ClarkeWright {
private:
    Node * depot;
    std::unordered_map<Node *,double> order;
    std::unordered_map<Node *, std::unordered_map<Node*,double>> costFunction;
    std::vector<Saving> savings;
    std::unordered_map<Node*, Route*> routes; //parvo mas funciona
    std::unordered_set<Route*> finalRoutes;
    double maxT;
    double maxQ;
    void sortSavings();
    void calculateSavings();
    void makeInitialRoutes();
public:
    ClarkeWright(Node * depot,
                 std::unordered_map<Node *,double> order,
                 std::unordered_map<Node *, std::unordered_map<Node*,double>> costFunction,
                 double maxT, double maxQ);
    ~ClarkeWright();
    void run();
    std::unordered_set<Route*> getRoutes(){return finalRoutes;};
};


#endif //VACCINEROUTER_CLARKEWRIGHT_H
