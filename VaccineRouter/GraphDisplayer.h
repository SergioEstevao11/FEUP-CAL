#ifndef VACCINEROUTER_GRAPHDISPLAYER_H
#define VACCINEROUTER_GRAPHDISPLAYER_H


#include "graph/Graph.h"

#include "lib/GraphViewerCpp/include/graphviewer.h"



class GraphDisplayer {
    Graph *graph;
    GraphViewer gv;
    static const unsigned int NUMCOLORS;
    static const sf::Color colors[];
public:
    GraphDisplayer(Graph * graph);
    void display(std::vector<std::vector<Edge*>> paths);
    void display();
    void setDefaultColor();
    void highlightEdges(std::vector<Edge*> path, const sf::Color &color); //provavelmente não funciona
    void highlightEdges(std::vector<GraphViewer::id_t> path, const sf::Color &color);
    void highLightNodes(std::vector<GraphViewer::id_t> path, const sf::Color &color);
    //////////////////////////
    void highlightPOI(std::unordered_map<Node *, double> &clients, std::vector<Node*> &depot);
    void highlightPath(std::vector<Edge*> path);
    void highlightRoutes(std::vector<std::vector<std::vector<Edge*>>> &routes);
    void traceAnimation(std::vector<Edge*> trace);
    void biTraceAnimation(std::vector<Edge*> &traceForward, std::vector<Edge*> &traceBackward);
};


#endif //VACCINEROUTER_GRAPHDISPLAYER_H
