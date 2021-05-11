//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_CLARKEWRIGHT_H
#define VACCINEROUTER_CLARKEWRIGHT_H


#include <unordered_set>
#include <unordered_map>
#include <vector>

#include "../graph/Node.h"

class ClarkeWright {
private:
    struct Saving{
        double save;
        Node * from;
        Node * to;
    };
    Node * depot;
    std::unordered_map<Node *,double> order;
    std::unordered_map<Node *, std::unordered_map<Node*,double>> costFunction;
    std::vector<Saving> savings;
    double maxT;
    double maxQ;
    bool cmp(Saving s1, Saving s2);
    void sortSavings();
    void calculateSavings();

public:
    void run();
};


#endif //VACCINEROUTER_CLARKEWRIGHT_H
