#include "MenuInterface.h"

int main() {
    std::string nodeString = "../maps/porto_full_nodes_xy.txt";
    std::string edgeString = "../maps/porto_full_edges.txt";
    std::string depotsString = "../maps/depots.txt";
    std::string clientsString = "../maps/clients.txt";
    std::string dataString = "../data.txt";
    Manager manager(nodeString, edgeString, depotsString, clientsString, dataString);
    MenuInterface menu(&manager);
    menu.mainMenuStart();
}
