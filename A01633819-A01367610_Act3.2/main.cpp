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
    cout << "\n---------- Dijkstra Algorithm ----------\n" << endl;
    for(int i = 0; i < nodes; i++){
        Utils::dijkstraFunction(adjMatrix, nodes, i);
    }
    Utils::floydFunction(adjMatrix, nodes);

    return 0;
}