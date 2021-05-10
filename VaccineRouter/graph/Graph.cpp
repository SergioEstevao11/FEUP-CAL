//
// Created by rodrigo on 10/05/2021.
//
#include "Graph.h"
#include <iostream>
#include <limits>

using namespace std;

const double Graph::INF = numeric_limits<double>::max();

bool Graph::nodeExists(Node *node) {
    return nodes.find(node) != nodes.end();
}

bool Graph::edgeExists(Edge *edge) {
    return adjList[edge->getBegin()].find(edge) != adjList[edge->getBegin()].end();
}

Graph::~Graph() {
    for(auto &node : nodes){
        for(auto &edge : adjList[node]){
            delete edge;
        }
    }
    for(auto &node : nodes){
        delete node;
    }
}

void Graph::addNode(Node *node) {
    if(nodeExists(node)){
         cout << "Invalid Node";
    }

    nodes.insert(node);
    adjList[node] = unordered_set<Edge *>();
}

void Graph::addEdge(Edge *edge) {
    if(!nodeExists(edge->getBegin()) || !nodeExists(edge->getEnd())){
        cout << "Invalid Edge";
    }
    if(edgeExists(edge)){
        cout << "Invalid Edge";
    }

    adjList[edge->getBegin()].insert(edge);
    predAdjList[edge->getEnd()].insert(edge);
}


