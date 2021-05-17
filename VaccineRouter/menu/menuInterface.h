#include "../GraphDisplayer.h"
#include <iostream>
#include <locale>
#include <iomanip>
#include <set>
#include <map>

using namespace std;

class menuInterface {

private:
    GraphDisplayer *graphD;

public:

    menuInterface(GraphDisplayer *gd);

    void showMap();
    void drawTitle();
    void drawMainMenu();
    void mainMenuHandler();
    int userChoice();
};

