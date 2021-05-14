//
// Created by rodrigo on 11/05/2021.
//

#include "ClarkeWright.h"

#include <algorithm>

using namespace std;

void ClarkeWright::sortSavings() {
  sort(savings.begin(), savings.end(), cmp);
}

bool cmp(Saving s1, Saving s2) {
    return s1.save > s2.save;
}

void ClarkeWright::calculateSavings() {
    for(auto & u : order){
        for(auto & v: order){
            if(u!=v){
                Saving saving;
                saving.from = u.first;
                saving.to = v.first;
                saving.save = costFunction[u.first][depot] + costFunction[depot][v.first]
                                                            - costFunction[u.first][v.first];
                savings.push_back(saving);
            }
        }
    }

}

void ClarkeWright::makeInitialRoutes() {
    for(auto & v : order){
        double weight = costFunction[depot][v.first] + costFunction[v.first][depot];
        Route * route = new Route(v.first, weight, v.second, maxT, maxQ);
        routes[v.first] = route;
    }
}

void ClarkeWright::run() {
    makeInitialRoutes();
    calculateSavings();
    sortSavings();
    for(auto & save : savings){
        if(save.save < 0) break;
        Route * from = routes[save.from];
        Route * to = routes[save.to];
        if(from == to) continue;
        if(from->isFirstNode(save.from) && to->isLastNode(save.to)){
            if(from->addRoute(to, save.save)){
                std::vector<Node*> updatedNodes = to->getNodes();
                for(auto & v : updatedNodes){
                    routes[v] = from;
                }
                delete to;
            }
        }
    }

    for(auto & v : routes){
        finalRoutes.insert(v.second);
    }
}

ClarkeWright::~ClarkeWright() {
    for(auto &r : finalRoutes){
        delete r;
    }
}
