//
// Created by rodrigo on 11/05/2021.
//

#include "Tarjan.h"

using namespace std;

Tarjan::Tarjan(Graph *graph) {
    this->graph = graph;
}

void Tarjan::setup() {
    for(auto &node : graph->nodes){
        SCC[node] = nullptr;
        id[node] = -1;
    }
}

void Tarjan::run() {
    setup();
    for(auto &node : graph->nodes){
        if(id[node] == -1){
            strongComponent(node);
        }
    }
}

void Tarjan::strongComponent(Node *node) {
    id[node] = index; lowLink[node] = index; index++;
    stack.push(node); onStack[node] = true;

    for(auto &edge : graph->adjList[node]){
        Node * v = edge->getEnd();
        if(id[v] == -1){
            strongComponent(v);
            lowLink[node] = min(lowLink[node], lowLink[v]);
        } else if (onStack[v]){
            lowLink[node] = min(lowLink[node], lowLink[v]);
        }
    }

    if(lowLink[node] == id[node]){
        while(!stack.empty()){
            Node * v = stack.top(); stack.pop();
            onStack[v] = false;

            SCC[v] = node;
            if(v == node) break;
        }
    }
}
