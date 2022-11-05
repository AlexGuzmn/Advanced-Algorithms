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
  vector<Edge*> minimumSpanningTreeVector;
  Algorithms::kruskal(&distancesMap, &minimumSpanningTreeVector);

  cout << "Minimum spanning tree:" << endl;
  for (int i = 0; i < minimumSpanningTreeVector.size(); i++) {
	cout << "Edge " << i << " from node " << minimumSpanningTreeVector[i]->getOrigin()->getId() << " to node " << minimumSpanningTreeVector[i]->getToNode()
		 ->getId() << " with weight " << minimumSpanningTreeVector[i]->getWeight() << endl;
  }

  return 0;
}