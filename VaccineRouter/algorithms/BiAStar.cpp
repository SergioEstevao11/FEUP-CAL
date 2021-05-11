//
// Created by rodrigo on 11/05/2021.
//

#include "BiAStar.h"

#include <queue>
#include <cmath>

using namespace std;

BiAStar::BiAStar(Graph *graph) {
    this->graph = graph;
}

void BiAStar::setup(Node * orig, Node * dest) {
    double uX = dest->getX() - orig->getX();
    double uY = dest->getY() - orig->getY();
    double sTot = sqrt(uX*uX + uY*uY);
    for(auto &node : graph->nodes){
        distForward[node] = Graph::INF;
        distBackward[node] = Graph::INF;
        visitedForward[node] = false;
        visitedBackward[node] = false;
        path[node] = nullptr;
        double vX = node->getX() - orig->getX();
        double vY = node->getY() - orig->getY();
        double dist = (uX*vX + uY*vY)/sqrt(vX*vX + vY*vY);
        heuristicForward[node] = sTot - dist;
        heuristicBackward[node] = dist;
    }
}

double BiAStar::run(Node *orig, Node *dest) {
    setup(orig,dest);
    priority_queue<pair<double, Node*>> qf;
    qf.push(make_pair(0 - (heuristicForward[orig] - heuristicBackward[orig])/2, orig));

    priority_queue<pair<double, Node*>> qb;
    qb.push(make_pair(0 - (heuristicBackward[dest] - heuristicForward[dest])/2, dest));

    distForward[orig] = 0;
    distBackward[dest] = 0;
    path[orig] = nullptr;

    double minDist = Graph::INF;

    while(!(qf.empty() || qb.empty())){
        Node * nf = qf.top().second; qf.pop();
        Node * nb = qb.top().second; qb.pop();
        if(distForward[nf] + distBackward[nb] >= minDist){
            return minDist;
        }
        if(!visitedForward[nf]){
            for(auto & edge : graph->adjList[nf]){
                Node * pr = edge->getEnd();
                double w = edge->getWeight();
                if(distForward[pr] > distForward[nf] + w){
                    distForward[pr] = distForward[nf] + w;
                    qf.push({-distForward[pr] - (heuristicForward[pr] - heuristicBackward[pr])/2, pr});
                    path[pr] = nf;
                }
                if(visitedBackward[pr])
                    minDist = min(minDist, distForward[nf] + w + distBackward[pr]);
            }
            visitedForward[nf] = true;
        }
        if(!visitedBackward[nb]){
            for(auto & edge : graph->predAdjList[nb]){
                Node * pr = edge->getBegin();
                double w = edge->getWeight();
                if(distBackward[pr] > distBackward[nb] + w){
                    distBackward[pr] = distBackward[nb] + w;
                    qb.push({-distBackward[pr] - (heuristicBackward[pr] - heuristicForward[pr])/2, pr});
                    path[nb] = pr;
                }
                if(visitedForward[pr])
                    minDist = min(minDist, distForward[pr] + w + distBackward[nb]);
            }
            visitedBackward[nb] = true;
        }
    }

    return Graph::INF;
}