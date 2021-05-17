//
// Created by rodrigo on 13/05/2021.
//

#ifndef VACCINEROUTER_GRAPHDISPLAYER_H
#define VACCINEROUTER_GRAPHDISPLAYER_H


#include "graph/Graph.h"

#include "lib/GraphViewerCpp/include/graphviewer.h"

class GraphDisplayer {
    Graph *graph;
    GraphViewer gv;
public:
    GraphDisplayer(Graph * graph);
    void display(std::vector<std::vector<Edge*>> paths);
    void display();
    void SetDefaultColor();
    void HighlightEdges(std::vector<GraphViewer::Edge*> path, const sf::Color &color); //provavelmente não funciona
    void HighlightEdges(std::vector<GraphViewer::id_t> path, const sf::Color &color);
    void HighLightNodes(std::vector<GraphViewer::id_t> path, const sf::Color &color);
};


#endif //VACCINEROUTER_GRAPHDISPLAYER_H
