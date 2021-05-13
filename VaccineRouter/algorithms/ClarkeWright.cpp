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
