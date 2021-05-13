//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_CLARKEWRIGHT_H
#define VACCINEROUTER_CLARKEWRIGHT_H


#include <unordered_set>
#include <unordered_map>
#include <vector>

#include "../graph/Node.h"

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
    double maxT;
    double maxQ;
    void sortSavings();
    void calculateSavings();
    //rotas conjuntos de pontos ordenados?
public:
    void run();
};


#endif //VACCINEROUTER_CLARKEWRIGHT_H
