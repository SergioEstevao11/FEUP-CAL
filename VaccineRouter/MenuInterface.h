#include "GraphDisplayer.h"
#include "Manager.h"

class MenuInterface {
private:
    Manager * manager;
    int readOption(int min, unsigned int max);
    void drawTitle();
    void drawMainMenu();
    void drawPathsAlgorithmsMenu();
    void drawSCCAlgorithmsMenu();
    void animationDisplay();
    void pathDisplay();
    void poiDisplay();
    void routesDisplay();
    void sccDisplay();
    int pathsMenu();
    Node* nodeChoice(bool isSource);
public:
    MenuInterface(Manager *manager);
    void mainMenuStart();

};

