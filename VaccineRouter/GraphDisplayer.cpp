//
// Created by rodrigo on 13/05/2021.
//

#include <iostream>
#include "graphviewer.h"
#include "GraphDisplayer.h"

using namespace std;
using gvNode = GraphViewer::Node;
using gvEdge = GraphViewer::Edge;

GraphDisplayer::GraphDisplayer(Graph *graph) {
    this->graph = graph;
}

void GraphDisplayer::display() {
    GraphViewer gv;
    gv.setScale(7.5);
    gv.setCenter(sf::Vector2f(2500, 0));

    for(auto &v : graph->getNodes()){
        gvNode &node = gv.addNode(v->getId(), sf::Vector2f(v->getX(), v->getY()));
        node.setOutlineThickness(0.0);
        node.setSize(5.0);
        node.setColor(GraphViewer::RED);
    }

    for(auto &e : graph->getEdges()){
        gvEdge &edge = gv.addEdge(e.first, gv.getNode(e.second->getBegin()->getId()), gv.getNode(e.second->getEnd()->getId()));
        edge.setThickness(1);
        edge.setColor(GraphViewer::BLACK);
    }

    gv.setEnabledNodes(true); // Disable node drawing
    gv.setEnabledEdgesText(false); // Disable edge text drawing
    gv.setZipEdges(false);

    gv.createWindow(1600, 900);
    gv.join();

}
