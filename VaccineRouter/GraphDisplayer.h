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
    /**
     * Initializes the graph viewer with the nodes and edges in graph
     * @param graph
     */
    GraphDisplayer(Graph * graph);
    /**
     * Creates a window and displays the graph
     */
    void display();
    void join();
    /**
     * Resets the graph viewer
     */
    void setDefaultColor();
    /**
     * Highlights all the edges of path with the color provided as argument
     * @param path
     * @param color
     */
    void highlightEdges(std::vector<Edge*> &path, const sf::Color &color);
    /**
     * Highlights in the graph viewer the points of interest (clients and depots)
     * @param clients
     * @param depot
     */
    void highlightPOI(std::unordered_map<Node *, double> &clients, std::vector<Node*> &depot);
    /**
     * Highlights in the graph viewer the path provided as argument
     * @param path
     */
    void highlightPath(std::vector<Edge*> &path);
    /**
     * Highlights in the graph viewer the routes provided as argument
     * @param routes
     */
    void highlightRoutes(std::vector<std::vector<std::vector<Edge*>>> &routes);
    /**
     * Highlights in the graph viewer the strongly connected components of the node provided as argument
     * @param scc
     * @param node
     */
    void highlightSCCNodes(std::unordered_map<Node *, Node*> &scc, Node * node);
    /**
     * Shows the trace of the algorithm's execution in a animation
     * @param traceForward
     * @param traceBackward
     */
    void traceAnimation(std::vector<Edge*> &traceForward, std::vector<Edge*> &traceBackward);
    /**
     * @brief Shows the path of the algorithm's execution in a animation
     * @param path
     */
    void pathAnimation(std::vector<Edge*> &path);
    /**
     * @brief Highlight a specific node with the parsed color
     * @param begin
     * @param color
     */
    void highlightNode(Node * node, sf::Color color);
};


#endif //VACCINEROUTER_GRAPHDISPLAYER_H
