#include <iostream>
#include <vector>
#include <limits>
#include "./src/Utils.h"
using namespace std;


int main(){
    int nodes, aux;
    vector<vector<int>> adjMatrix;

    cin >> nodes;
    Utils::createMtx(adjMatrix, nodes);
    Utils::printMtx(adjMatrix);
    Utils::dijkstraFunction(adjMatrix, nodes);
    Utils::floydFunction(adjMatrix, nodes);

    return 0;
}