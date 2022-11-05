#ifndef ADVANCED_ALGORITHMS_ACTINT_2_SRC_EDGE_H_
#define ADVANCED_ALGORITHMS_ACTINT_2_SRC_EDGE_H_

#include <iostream>
#include "Node.h"


class Node;

class Edge{
 public:
  Edge(Node*, int);
  Edge(Node*, Node*, int);
  void setOrigin(Node*);
  Node* getOrigin();
  Node* getToNode();
  int getWeight();

  void print();

 private:
  Node *originNode;
  Node *toNode;
  int weight;
};

Edge::Edge(Node *toNode, int weight){
  this->toNode = toNode;
  this->weight = weight;
}

void Edge::setOrigin(Node *originNode){
  this->originNode = originNode;
}

Node* Edge::getOrigin(){
  return originNode;
}

Node* Edge::getToNode(){
  return toNode;
}

int Edge::getWeight(){
  return weight;
}

Edge::Edge(Node *originNode, Node *toNode, int weight){
  this->originNode = originNode;
  this->toNode = toNode;
  this->weight = weight;
}


#endif //ADVANCED_ALGORITHMS_ACTINT_2_SRC_EDGE_H_
