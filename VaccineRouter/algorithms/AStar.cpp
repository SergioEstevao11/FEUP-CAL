//
// Created by rodrigo on 11/05/2021.
//

#include "AStar.h"

#include <queue>
#include <chrono>

typedef std::chrono::high_resolution_clock hrc;

using namespace std;

AStar::AStar(Graph *graph) {
    this->graph = graph;
}

void AStar::setup(Node * dest) {
    for(auto &node : graph->nodes){
        dist[node] = Graph::INF;
        visited[node] = false;
        path[node] = nullptr;
        heuristic[node] = dest->dist(node);
    }
}

double AStar::run(Node *orig, Node *dest) {
    auto startTime = hrc::now();
    setup(dest);
    priority_queue<pair<double, Node*>> q;
    q.push(make_pair(0 - heuristic[orig], orig));
    dist[orig] = 0;
    path[orig] = nullptr;
    while(!q.empty()){
        Node * out = q.top().second; q.pop();
        if(visited[out]) continue;
        if(out == dest) {
            auto finishTime = hrc::now();
            executionTime = chrono::duration_cast<std::chrono::milliseconds>(finishTime - startTime).count();
            return dist[dest];
        }
        visited[out] = true;
        for(auto &edge : graph->adjList[out]){
            Node * in = edge->getEnd();
            double w = edge->getWeight();
            if(dist[in] > dist[out] + w){
                dist[in] = dist[out] + w;
                q.push({-dist[in] - heuristic[in], in});
                path[in] = edge;
            }
            trace.push_back(edge);
        }
    }
    auto finishTime = hrc::now();
    executionTime = chrono::duration_cast<std::chrono::milliseconds>(finishTime - startTime).count();
    return Graph::INF;
}

std::vector<Edge *> AStar::getPath(Node *source, Node *dest) {
    vector<Edge *> edgePath;
    Node * it = dest;
    while(path[it] != nullptr){
        edgePath.push_back(path[it]);
        it = path[it]->getBegin();
    }
    return edgePath;
}

std::vector<Edge *> &AStar::getTrace() {
    return trace;
}

unsigned int AStar::getExecutionTime() const {
    return executionTime;
}
