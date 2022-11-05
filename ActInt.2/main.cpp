#include <iostream>
#include <map>

using namespace std;


#include "src/Utils.h"
#include "src/Algorithms.h"

int main() {
  int n;
  cin >> n;

  Utils::getInstance()->setMatrixSize(&n);
  int **distanceMtx = Utils::getInstance()->getMatrixFromInput();
  map<int, Node *> distancesMap = Utils::getInstance()->getMapFromMatrix(distanceMtx);

  // Utils::printNodesMap(&distancesMap);
  vector<Edge*> t = Algorithms::kruskal(&distancesMap);

  return 0;
}