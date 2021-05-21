#include "GraphDisplayer.h"
#include "Manager.h"

class MenuInterface {
private:
    Manager * manager;
    int readOption(int min, unsigned int max);
    void drawTitle();
    void drawMainMenu();
    void drawPathsAlgorithmsMenu();
    void animationMenu();
    void pathMenu();
    void poiMenu();
    void routesMenu();
    void drawSCCAlgorithmsMenu();
public:
    MenuInterface(Manager *manager);
    void mainMenuStart();

};

