//
// Created by rodrigo on 10/05/2021.
//

#include "Dijkstra.h"

#include <queue>

using namespace std;

Dijkstra::Dijkstra(Graph *graph) {
    this->graph = graph;
}

void Dijkstra::setup() {
    for(auto &node : graph->nodes){
        dist[node] = Graph::INF;
        visited[node] = false;
        path[node] = nullptr;
    }
}

void Dijkstra::run(Node *node) {
    setup();
    priority_queue<pair<double, Node*>> q;
    q.push(make_pair(0, node));
    dist[node] = 0;
    path[node] = nullptr;
    while(!q.empty()){
        Node * out = q.top().second; q.pop();
        if(visited[out]) continue;
        visited[out] = true;
        for(auto &edge : graph->adjList[out]){
            Node * in = edge->getEnd();
            double w = edge->getWeight();
            if(dist[in] > dist[out] + w){
                dist[in] = dist[out] + w;
                q.push({-dist[in], in});
                path[in] = out;
            }
        }
    }
}