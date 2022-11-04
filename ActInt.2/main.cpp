#include <iostream>

using namespace std;

#include "src/Utils.h"

int main() {
  int n;
  cin >> n;

  Utils::getInstance()->setMatrixSize(&n);
  int **distanceMtx = Utils::getInstance()->getMatrixFromInput();
  map<int, Node *> distancesMap = Utils::getInstance()->getMapFromMatrix(distanceMtx);

  Utils::printNodesMap(&distancesMap);

  return 0;
}