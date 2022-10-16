/*

Activity 3.4 Implementation of Graph coloring

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

*/

#include <iostream>
#include <vector>
using namespace std;

#include "./src/Utils.h"

int main(){

    int nodes;
    vector< vector<int> > graph;

    cin >> nodes;
    Utils::createMtx(graph, nodes);
    Utils::printMtx(graph);
    Utils::graphColoring(graph, nodes);

    return 0;
}