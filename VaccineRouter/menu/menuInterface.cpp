#include "menuInterface.h"


menuInterface::menuInterface(GraphDisplayer graph) : graph(graph){}


void menuInterface::mainMenuHandler() {
    drawTitle();
    drawMainMenu();
    int option = userChoice();

    switch(option){
        case 1:
            showMap();
            break;
        default:
            return;
    }

}



void menuInterface::drawTitle(){
    system("cls");
    cout <<"========================================================================="       << endl;
    cout << " _   _                _             ______            _                       " << endl;
    cout << "| | | |              (_)            | ___ \\          | |                     " << endl;
    cout << "| | | | __ _  ___ ___ _ _ __   ___  | |_/ /___  _   _| |_ ___ _ __            " << endl;
    cout << "| | | |/ _` |/ __/ __| | '_ \\ / _ \\ |    // _ \\| | | | __/ _ \\ '__|       " << endl;
    cout << "\\ \\_/ / (_| | (_| (__| | | | |  __/ | |\\ \\ (_) | |_| | ||  __/ |          " << endl;
    cout << " \\___/ \\__,_|\\___\\___|_|_| |_|\\___| \\_| \\_\\___/ \\__,_|\\__\\___|_|   " << endl;
    cout << "                                                                              " << endl;
    cout << "========================================================================="      << "\n"  << endl;

}

void menuInterface::drawMainMenu() {

    cout << "       MAIN MENU   \n" << endl;
    cout <<"=============================" << endl;
    cout << " 1. Show Map" << endl;
    cout << " 2. Show Points of Interest " << endl;
    cout << " 3. Exit" << endl;
    cout <<"=============================" << endl;

}


int menuInterface::userChoice(){
    int choice;
    set<int> options = {1 , 2 , 3};

    cout << endl << "Make your choice: " ;

    cin >> choice;
    while(options.find(choice) == options.end()){
        cin.clear();
        cin.ignore(10000, '\n');
        cerr << "Invalid Input! Please choose again:";
        cin >> choice ;
    }
    cin.ignore(10000, '\n');
    return choice;
}


void menuInterface::showMap(){
    graph.display();
}