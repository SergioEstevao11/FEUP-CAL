//
// Created by rodrigo on 10/05/2021.
//

#include "BiDijkstra.h"

#include <queue>
#include <chrono>

typedef std::chrono::high_resolution_clock hrc;

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
        pathf[node] = nullptr;
        pathb[node] = nullptr;
    }
}

double BiDijkstra::run(Node *orig, Node *dest) {
    auto startTime = hrc::now();
    setup();
    priority_queue<pair<double, Node*>> qf;
    qf.push(make_pair(0, orig));

    priority_queue<pair<double, Node*>> qb;
    qb.push(make_pair(0, dest));

    distForward[orig] = 0;
    distBackward[dest] = 0;
    pathf[orig] = nullptr;

    double minDist = Graph::INF;

    while(!(qf.empty() || qb.empty())){
        Node * nf = qf.top().second; qf.pop();
        Node * nb = qb.top().second; qb.pop();
        if(distForward[nf] + distBackward[nb] >= minDist){
            auto finishTime = hrc::now();
            executionTime = chrono::duration_cast<std::chrono::milliseconds>(finishTime - startTime).count();
            return minDist;
        }
        if(!visitedForward[nf]){
            for(auto & edge : graph->adjList[nf]){
                Node * pr = edge->getEnd();
                double w = edge->getWeight();
                if(distForward[pr] > distForward[nf] + w){
                    distForward[pr] = distForward[nf] + w;
                    qf.push({-distForward[pr], pr});
                    pathf[pr] = edge;
                }
                if(visitedBackward[pr]){
                    if(distForward[nf] + w + distBackward[pr] < minDist){
                        minDist = distForward[nf] + w + distBackward[pr];
                        midPoint = pr;
                        pathf[pr] = edge;
                    }
                }
                traceForward.push_back(edge);
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
                    pathb[pr] = edge;
                }
                if(visitedForward[pr])
                    if( distForward[pr] + w + distBackward[nb] < minDist){
                        minDist = distForward[pr] + w + distBackward[nb];
                        midPoint = nb;
                        pathf[nb] = edge;
                    }
                traceBackward.push_back(edge);
            }
            visitedBackward[nb] = true;
        }
    }
    auto finishTime = hrc::now();
    executionTime = chrono::duration_cast<std::chrono::milliseconds>(finishTime - startTime).count();
    return Graph::INF;
}

std::vector<Edge *> BiDijkstra::getPath(Node *source, Node *dest) {
    vector<Edge *> edgePath;
    Node * it = midPoint;
    while(pathf[it] != nullptr){
        edgePath.push_back(pathf[it]);
        it = pathf[it]->getBegin();
    }
    it = midPoint;
    while(pathb[it] != nullptr){
        edgePath.push_back(pathb[it]);
        it = pathb[it]->getEnd();
    }
    return edgePath;
}

unsigned int BiDijkstra::getExecutionTime() const {
    return executionTime;
}
