#ifndef ADVANCED_ALGORITHMS_ACTINT_2_SRC_EDGE_H_
#define ADVANCED_ALGORITHMS_ACTINT_2_SRC_EDGE_H_

#include <iostream>
#include "Node.h"


class Node;

class Edge{
 public:
  Edge(Node*, int);
  Node *toNode;
  int weight;
};

Edge::Edge(Node *toNode, int weight){
  this->toNode = toNode;
  this->weight = weight;
}

#endif //ADVANCED_ALGORITHMS_ACTINT_2_SRC_EDGE_H_
