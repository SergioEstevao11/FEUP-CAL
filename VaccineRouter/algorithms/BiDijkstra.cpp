//
// Created by rodrigo on 10/05/2021.
//

#include "BiDijkstra.h"

#include <queue>

using namespace std;

BiDijkstra::BiDijkstra(Graph *graph) {
    this->graph = graph;
}

void BiDijkstra::setup() {
    for(auto &node : graph->nodes){
        distForward[node] = Graph::INF;
        distBackward[node] = Graph::INF;
        visitedForward[node] = false;
        visitedBackward[node] = false;
        path[node] = nullptr;
    }
}

double BiDijkstra::run(Node *orig, Node *dest) {
    setup();
    priority_queue<pair<double, Node*>> qf;
    qf.push(make_pair(0, orig));

    priority_queue<pair<double, Node*>> qb;
    qb.push(make_pair(0, dest));

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
                    qf.push({-distForward[pr], pr});
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
                    qb.push({-distBackward[pr], pr});
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
