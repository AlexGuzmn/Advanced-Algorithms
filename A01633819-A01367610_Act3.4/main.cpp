#include <iostream>
#include <vector>
using namespace std;

#include "./src/Utils.h"

int main(){
    
    int nodes;
    vector<vector<int>> graph;

    cin >> nodes;
    Utils::createMtx(graph, nodes);
    Utils::printMtx(graph);
    Utils::graphColoring(graph, nodes);

    return 0;
}