//
// Created by rodrigo on 10/05/2021.
//
#include "Kosaraju.h"

#include <chrono>

typedef std::chrono::high_resolution_clock hrc;

using namespace std;

Kosaraju::Kosaraju(Graph * graph) {
    this->graph = graph;
}

void Kosaraju::setup() {
    for(auto &node : graph->nodes){
        SCC[node] = nullptr;
        visited[node] = false;
    }
}

void Kosaraju::run() {
    auto startTime = hrc::now();
    setup();
    for(auto &node : graph->nodes){
        DFSFirst(node);
    }
    while(!stack.empty()){
        Node * node = stack.top(); stack.pop();
        DFSAssign(node,node);
    }
    auto finishTime = hrc::now();
    executionTime = chrono::duration_cast<std::chrono::milliseconds>(finishTime - startTime).count();
}

void Kosaraju::DFSFirst(Node * node) {
    if(visited[node]) return;
    visited[node] = true;

    for(auto &edge : graph->adjList[node]){
        DFSFirst(edge->getEnd());
    }

    stack.push(node);
}

void Kosaraju::DFSAssign(Node * node, Node * component) {
    if(SCC[node] != nullptr) return;
    SCC[node] = component;
    for(auto &edge: graph->predAdjList[node]){
        DFSAssign(edge->getBegin(), component);
    }
}

std::unordered_map<Node *, Node *>& Kosaraju::getSCC() {
    return SCC;
}

unsigned int Kosaraju::getExecutionTime() const {
    return executionTime;
}
