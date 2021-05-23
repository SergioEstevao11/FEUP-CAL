//
// Created by rodrigo on 11/05/2021.
//

#ifndef VACCINEROUTER_CLARKEWRIGHT_H
#define VACCINEROUTER_CLARKEWRIGHT_H


#include <unordered_set>
#include <unordered_map>
#include <vector>

#include "../graph/Node.h"
#include "Route.h"

/**
 * @brief Struct that holds the savings gained joining two different orders
 */
struct Saving{
    double save;
    Node * from;
    Node * to;
};

bool cmp(Saving s1, Saving s2);

class ClarkeWright {
private:
    Node * depot;
    std::unordered_map<Node *,double> order;
    std::unordered_map<Node *, std::unordered_map<Node*,double>> costFunction;
    std::vector<Saving> savings;
    std::unordered_map<Node*, Route*> routes;
    std::unordered_set<Route*> finalRoutes;
    double maxT;
    double maxQ;
    unsigned int executionTime;

    /**
     * @brief Sorts the savings by descending order
     */
    void sortSavings();

    /**
     * @brief Calculates the savings gained
     */
    void calculateSavings();

    /**
     * @brief Initializes the default routes
     */
    void makeInitialRoutes();
public:

    /**
     * @brief  Clarke Wright constructor
     *
     * @param depot Pointer to the depot node
     * @param order Total vaccine orders and respective size
     * @param costFunction  Data structure containing the travelling costs
     * @param maxT  Maximum traveling time per vehicle trip
     * @param maxQ  Maximum quantity a vehicle can carry
     */
    ClarkeWright(Node * depot,
                 std::unordered_map<Node *,double> order,
                 std::unordered_map<Node *, std::unordered_map<Node*,double>> costFunction,
                 double maxT, double maxQ);

    /**
     * @brief Executes the algorithm
     */
    void run();

    /**
     * @brief   Retrieves the re-arranged routes
     *
     * @return  Unordered set containing all the routes
     */
    std::unordered_set<Route*> getRoutes(){return finalRoutes;};

    /**
     * @brief    Retrieves the time it took complete the previous execution of the algorithm
     *
     * @return  Time in milliseconds
     */
    unsigned int getExecutionTime();

    /**
     * @brief Clarke Wright destructor
     */
    ~ClarkeWright();
};


#endif //VACCINEROUTER_CLARKEWRIGHT_H
