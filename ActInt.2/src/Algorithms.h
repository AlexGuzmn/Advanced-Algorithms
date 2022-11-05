//
// Created by Jose Naime on 04/11/22.
//

#ifndef ADVANCED_ALGORITHMS_ACTINT_2_SRC_ALGORITHMS_H_
#define ADVANCED_ALGORITHMS_ACTINT_2_SRC_ALGORITHMS_H_

#include <vector>
#include "classes/Node.h"

class Algorithms{
 public:
  // Used for exercise 1 - Find the optimal way to connect all the cities
  static vector<Edge*> kruskal(map<int, Node *> *nodesMap);
};

vector<Edge*> Algorithms::kruskal(map<int, Node*> *nodesMap) {
  vector<Edge*> edges;

  for (auto it = nodesMap->begin(); it != nodesMap->end(); it++) {
	vector<Edge*> nodeEdges = it->second->getEdges();
	for (int i = 0; i < nodeEdges.size(); i++) {
	  nodeEdges[i]->setOrigin(it->second);
	  edges.push_back(nodeEdges[i]);
	}
  }

  // print all edges
  cout << "All edges:" << endl;
  for (int i = 0; i < edges.size(); i++) {
	cout << "Edge " << i << " from node " << edges[i]->getOrigin()->getId() << " to node " << edges[i]->getToNode()
	->getId() << " with weight " << edges[i]->getWeight() << endl;
  }

  return edges;

}

#endif //ADVANCED_ALGORITHMS_ACTINT_2_SRC_ALGORITHMS_H_
