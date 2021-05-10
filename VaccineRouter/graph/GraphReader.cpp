//
// Created by rodrigo on 10/05/2021.
//
#include "GraphReader.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

GraphReader::GraphReader(Graph * graph){
    this->graph = graph;
}
void GraphReader::readNodes(std::string &filename){
    ifstream inFile;
    inFile.open(filename);

    if(!inFile.is_open()){
        cout << "Unable to open File" << endl;
    } else{
        unsigned int numNodes;
        inFile >> numNodes;
        inFile.ignore();

        for(unsigned int i = 0; i < numNodes; i++){
            unsigned int id;
            double x, y;
            char dum;
            string tmp;

            getline(inFile, tmp);
            istringstream iss(tmp);
            iss >> dum >> id
                >> dum >> x
                >> dum >> y;

            Node * node = new Node(id,x, y);

            graph->addNode(node);
        }
    }
}
void GraphReader::readEdges(std::string &filename){
    ifstream inFile;
    inFile.open(filename);

    if(!inFile.is_open()){
        cout << "Unable to open File" << endl;
    } else {
        unsigned int numEdges;
        inFile >> numEdges;
        inFile.ignore();

        for(unsigned int i = 0; i < numEdges; i++){
            unsigned int idOut, idIn;
            char dum;
            string tmp;

            getline(inFile, tmp);
            istringstream iss(tmp);
            iss >> dum >> idOut
                >> dum >> idIn;

            Edge * edge = new Edge(graph->getNode(idOut), graph->getNode(idIn));
            graph->addEdge(edge);
        }

    }
}