//
// Created by rodrigo on 13/05/2021.
//

#include <iostream>
#include <zconf.h>
#include "graphviewer.h"
#include "GraphDisplayer.h"

using namespace std;
using gvNode = GraphViewer::Node;
using gvEdge = GraphViewer::Edge;

const unsigned int GraphDisplayer::NUMCOLORS = 6;

const sf::Color GraphDisplayer::colors[] = {
        GraphViewer::RED,
        GraphViewer::BLUE,
        GraphViewer::YELLOW,
        GraphViewer::PINK,
        GraphViewer::MAGENTA
};

GraphDisplayer::GraphDisplayer(Graph *graph) {
    this->graph = graph;
    gv.setScale(7.5);
    gv.setCenter(sf::Vector2f(2500, 0));

    for(auto &v : graph->getNodes()){
        gvNode &node = gv.addNode(v->getId(), sf::Vector2f(v->getX(), v->getY()));
    }
    for(auto &e : graph->getEdges()){
        gvEdge &edge = gv.addEdge(e.second, gv.getNode(e.first->getBegin()->getId()), gv.getNode(e.first->getEnd()->getId()));
    }

    setDefaultColor();
}

void GraphDisplayer::setDefaultColor(){
    for(auto &v : gv.getNodes()){
        v->setOutlineThickness(0.0);
        v->setSize(0.0);
        v->setColor(GraphViewer::WHITE);
    }
    for(auto &e : gv.getEdges()){
        e->setThickness(1);
        e->setColor(GraphViewer::BLACK);
    }
}

void GraphDisplayer::highlightEdges(std::vector<Edge*> &path, const sf::Color &color){
    for(auto &e : path){
        gvEdge &edge = gv.getEdge(graph->getEdgeId(e));
        edge.setColor(color);
        edge.setThickness(5);
    }
}

void GraphDisplayer::display(){
    gv.createWindow(1600, 900);
}

void GraphDisplayer::highlightPOI(unordered_map<Node*,double> &clients, vector<Node *> &depot) {
    for(auto & c : clients){
        gvNode &node = gv.getNode(c.first->getId());
        node.setColor(GraphViewer::ORANGE);
        node.setOutlineThickness(3);
        node.setSize(40);
    }

    for(auto & d : depot){
        gvNode &node = gv.getNode(d->getId());
        node.setColor(GraphViewer::GREEN);
        node.setSize(40);
    }
}

void GraphDisplayer::highlightPath(std::vector<Edge *> &path) {
    highlightEdges(path, GraphViewer::RED);
}

void GraphDisplayer::traceAnimation(std::vector<Edge *> &traceF, std::vector<Edge *> &traceB) {
    usleep(1000000);
    for(auto it1 = traceF.begin(), it2 = traceB.begin(); it1 != traceF.end() || it2 != traceB.end();){
        gv.lock();
        if(it1 != traceF.end()){
            gvEdge &edge = gv.getEdge(graph->getEdgeId(*(it1)));
            edge.setColor(GraphViewer::RED);
            edge.setThickness(5.0);
            it1++;
        }
        gv.unlock();
        gv.lock();
        if(it2 != traceB.end()){
            gvEdge &edge = gv.getEdge(graph->getEdgeId(*(it2)));
            edge.setColor(GraphViewer::GREEN);
            edge.setThickness(5.0);
            it2++;
        }
        gv.unlock();
        usleep(100);
    }
}

void GraphDisplayer::pathAnimation(std::vector<Edge*> &path){
    for(auto &e : path){
        gvEdge &edge = gv.getEdge(graph->getEdgeId(e));
        edge.setColor(GraphViewer::BLUE);
        edge.setThickness(5);
        usleep(20000);
    }
}


void GraphDisplayer::highlightRoutes(vector<std::vector<std::vector<Edge *>>> &routes) {
    for(auto &depotRoutes : routes){
        for(int i = 0; i < depotRoutes.size(); i++){
            highlightEdges(depotRoutes[i], colors[i % NUMCOLORS]);
        }
    }

}

void GraphDisplayer::join() {
    gv.join();
}

void GraphDisplayer::highlightSCCNodes(unordered_map<Node *, Node *> &scc, Node *node) {
    for(auto &comp : scc){
        if(scc[node] == comp.second){
            gvNode &node = gv.getNode(comp.first->getId());
            node.setColor(GraphViewer::RED);
            node.setSize(10);
        }
    }
}

void GraphDisplayer::highlightNode(Node * node, sf::Color color){
    if (node == nullptr) return;
    gvNode &sourceNode = gv.getNode(node->getId());
    sourceNode.setColor(color);
    sourceNode.setOutlineThickness(6);
    sourceNode.setSize(30);
}

