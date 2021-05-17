//
// Created by rodrigo on 13/05/2021.
//

#include <iostream>
#include "graphviewer.h"
#include "GraphDisplayer.h"
#include "lib/GraphViewerCpp/SFML/include/SFML/System.hpp"

using namespace std;
using gvNode = GraphViewer::Node;
using gvEdge = GraphViewer::Edge;

GraphDisplayer::GraphDisplayer(Graph *graph) {
    this->graph = graph;
    gv.setScale(7.5);
    gv.setCenter(sf::Vector2f(2500, 0));

    for(auto &v : graph->getNodes()){
        gvNode &node = gv.addNode(v->getId(), sf::Vector2f(v->getX(), v->getY()));
    }
    for(auto &e : graph->getEdges()){
        gvEdge &edge = gv.addEdge(e.first, gv.getNode(e.second->getBegin()->getId()), gv.getNode(e.second->getEnd()->getId()));
    }

    SetDefaultColor();
}

void GraphDisplayer::SetDefaultColor(){
    for(auto &v : gv.getNodes()){
        v->setOutlineThickness(0.0);
        v->setSize(5.0);
        v->setColor(GraphViewer::BLUE);
    }
    for(auto &e : gv.getEdges()){
        e->setThickness(1);
        e->setColor(GraphViewer::BLACK);
    }
}

void GraphDisplayer::HighlightEdges(std::vector<GraphViewer::Edge*> path, const sf::Color &color){
    for(auto &e : path){
        e->setColor(color);
    }
}

void GraphDisplayer::HighlightEdges(std::vector<GraphViewer::id_t> path, const sf::Color &color){
    for(auto &id : path){
        auto e = gv.getEdge(id);
        e.setColor(color);
    }
}

void GraphDisplayer::HighLightNodes(std::vector<GraphViewer::id_t> nodes, const sf::Color &color){
    for(auto &id : nodes){
        auto n = gv.getNode(id);
        n.setColor(color);
    }
}

void GraphDisplayer::display(std::vector<std::vector<Edge*>> paths) {
    /*
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
    }*/



    gv.setEnabledNodes(true); // Disable node drawing
    gv.setEnabledEdgesText(false); // Disable edge text drawing
    gv.setZipEdges(false);

    gv.createWindow(1600, 900);
    gv.join();

}

void GraphDisplayer::display(){

    gv.setEnabledNodes(true); // Disable node drawing
    gv.setEnabledEdgesText(false); // Disable edge text drawing
    gv.setZipEdges(false);

    gv.createWindow(1600, 900);
    gv.join();
}
