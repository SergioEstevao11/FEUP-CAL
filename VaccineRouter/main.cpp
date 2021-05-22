#include "MenuInterface.h"

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
