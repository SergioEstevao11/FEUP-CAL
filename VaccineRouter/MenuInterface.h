#include "GraphDisplayer.h"
#include "Manager.h"

class MenuInterface {
private:
    Manager * manager;
    /**
     * Asks for the user's choice when presented with the menu options
     * @param min minimum number user can choose
     * @param max maximum number user can choose
     * @return choice
     */
    static int readOption(int min, unsigned int max);
    /**
     * Draws the main logo of the program
     */
    static void drawTitle();
    /**
     * Draws the main menu
     */
    static void drawMainMenu();
    /**
     * Draws the menu which displays the algorithms available to calculate paths
     */
    static void drawPathsAlgorithmsMenu();
    /**
     * Draws the menu which displays the algorithms available to calculate the strongly connected components
     */
    static void drawSCCAlgorithmsMenu();
    void animationDisplay();
    void pathDisplay();
    /**
     * Displays the points of interest
     */
    void poiDisplay();
    /**
     * Displays the routes
     */
    void routesDisplay();
    /**
     * Displays the strongly connected components according to each algorithm
     */
    void sccDisplay();
    /**
     * Draws the menu which displays the algorithms available to calculate paths and asks for the user's choice
     * @return user's choice
     */
    static int pathsMenu();
    /**
     * Asks the user to choose a node
     * @param isSource
     * @return user's choice
     */
    Node* nodeChoice(bool isSource);
public:
    /** @brief MenuInterface Constructor
     *
     * @param manager
     */
    explicit MenuInterface(Manager *manager);
    /**
     * Function that controls the program and interaction with the user
     */
    void mainMenuStart();

};

