#include <iostream>
#include <vector>
#include "./src/Utils.h"

using namespace std;


int main() {
    int nodes;
    vector < vector<int> > adjMatrix;

    cin >> nodes;
    Utils::createMtx(adjMatrix, nodes);
    Utils::printMtx(adjMatrix);
    Utils::dijkstraFunction(adjMatrix, nodes);
    Utils::floydFunction(adjMatrix, nodes);

    return 0;
}