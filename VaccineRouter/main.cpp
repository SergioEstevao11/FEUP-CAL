#include "MenuInterface.h"
#include "graph/GraphReader.h"
#include "algorithms/Kosaraju.h"
#include "algorithms/Tarjan.h"

#include <chrono>
#include <iostream>

typedef std::chrono::high_resolution_clock hrc;

using namespace std;

int main() {
    std::string nodeS = "../maps/porto_full_nodes_xy.txt";
    std::string edgeS = "../maps/porto_full_edges.txt";
    std::string depotsS = "../maps/depots.txt";
    std::string clientsS = "../maps/clients.txt";
    Manager manager(nodeS, edgeS, depotsS, clientsS);
    MenuInterface menu(&manager);
    menu.mainMenuStart();
}
