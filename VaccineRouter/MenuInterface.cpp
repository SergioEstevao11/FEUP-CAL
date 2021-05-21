#include "MenuInterface.h"

#include <iostream>


using namespace std;

MenuInterface::MenuInterface(Manager *manager) {
    this->manager = manager;
}



void MenuInterface::drawTitle(){
    system("cls");
    cout <<"===============================================================================" << endl
         << " _   _                _             ______            _                       " << endl
         << "| | | |              (_)            | ___ \\          | |                     " << endl
         << "| | | | __ _  ___ ___ _ _ __   ___  | |_/ /___  _   _| |_ ___ _ __            " << endl
         << "| | | |/ _` |/ __/ __| | '_ \\ / _ \\ |    // _ \\| | | | __/ _ \\ '__|       " << endl
         << "\\ \\_/ / (_| | (_| (__| | | | |  __/ | |\\ \\ (_) | |_| | ||  __/ |          " << endl
         << " \\___/ \\__,_|\\___\\___|_|_| |_|\\___| \\_| \\_\\___/ \\__,_|\\__\\___|_|   " << endl
         << "                                                                              " << endl
         << "==============================================================================" << "\n"  << endl;

}

void MenuInterface::drawMainMenu() {
    cout << "       MAIN MENU            " << endl
         <<"=============================" << endl
         << "Show Map                 [1]" << endl
         << "Show Points of Interest  [2]" << endl
         << "Show SCC's               [3]" << endl
         << "Calculate Routes         [4]" << endl
         << "Calculate Shortest Path  [5]" << endl
         << "Algorithm Visualizer     [6]" << endl
         << "Exit                     [0]" << endl
         <<"=============================" << endl;
}

void MenuInterface::drawPathsAlgorithmsMenu() {
    cout << "       ALGORITHM            " << endl
         <<"=============================" << endl
         << "Dijkstra                 [1]" << endl
         << "Bidirectional Dijkstra   [2]" << endl
         << "A star (A*)              [3]" << endl
         << "Back                     [0]" << endl
         <<"=============================" << endl;
}

void MenuInterface::drawSCCAlgorithmsMenu() {
    cout << "       ALGORITHM            " << endl
         <<"=============================" << endl
         << "Dijkstra                 [1]" << endl
         << "Bidirectional Dijkstra   [2]" << endl
         << "A star (A*)              [3]" << endl
         << "Back                     [0]" << endl
         <<"=============================" << endl;
}

int MenuInterface::readOption(int min, unsigned int max) {
    int option;
    while (true) {
        cout << "Your option: ";
        if (cin >> option && option >= min && option <= max) {
            cin.ignore(1000, '\n');
            return option;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cerr << endl
                 << "Invalid input. Please try again:" << endl
                 << endl;
        }
    }
}

void MenuInterface::mainMenuStart() {
    drawTitle();
    int option;
    do {
        drawMainMenu();

        option = readOption(0,6);
        switch(option){
            case 1: {
                GraphDisplayer gd(manager->getGraph());
                gd.display();
                gd.join();
            }
                break;
            case 2:
                poiMenu();
                break;
            case 3:
                break;
            case 4:
                routesMenu();
                break;
            case 5:
                pathMenu();
                break;
            case 6:
                animationMenu();
                break;
        }
    } while(option != 0);
}

void MenuInterface::animationMenu() {
    GraphDisplayer gd(manager->getGraph());
    drawPathsAlgorithmsMenu();
    int option = readOption(0,3);
    vector<Edge*> pathForward;
    vector<Edge*> pathBackward;
    manager->getTrace(option, pathForward, pathBackward, 11396, 11320);
    gd.display();
    gd.traceAnimation(pathForward, pathBackward);
    gd.join();
}

void MenuInterface::pathMenu() {
    GraphDisplayer gd(manager->getGraph());
    drawPathsAlgorithmsMenu();
    int option = readOption(1,3);
    vector<Edge*> path;
    unsigned int time = 3;
    manager->getPath(option, time, path, 11396, 11320);
    cout << "Path calculated in: " << time << "ms." << endl;
    gd.highlightPath(path);
    gd.display();
    gd.join();
}

void MenuInterface::poiMenu() {
    GraphDisplayer gd(manager->getGraph());
    vector<Node*> depots;
    unordered_map<Node*, double> clients;
    manager->getPOI(depots, clients);
    gd.highlightPOI(clients, depots);
    gd.display();
    gd.join();
}

void MenuInterface::routesMenu() {

}


