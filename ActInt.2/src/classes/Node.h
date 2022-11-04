#ifndef ADVANCED_ALGORITHMS_ACTINT_2_SRC_NODE_H_
#define ADVANCED_ALGORITHMS_ACTINT_2_SRC_NODE_H_

#include <iostream>
#include <vector>
#include "Edge.h"

class Node{
 public:
  Node(int id);
  void addEdge(Node*, int);
  void printEdges();
 private:
  unsigned int id;
  vector<Edge*> edges;
};

Node::Node(int id){
  this->id = id;
}

void Node::addEdge(Node *toNode, int weight){
  // We can't allow to add an edge to itself
  if (toNode->id == this->id){
	cout << "Error: Can't add an edge to itself" << endl;
	return;
  }

  Edge *edge = new Edge(toNode, weight);
  edges.push_back(edge);
}

void Node::printEdges(){
  cout << "- Node " << this->id << " has " << edges.size() << " edges" << endl;
  for (int i = 0; i < edges.size(); i++){
	cout << "  > Edge " << i << " to node " << edges[i]->toNode->id << " with weight " << edges[i]->weight << endl;
  }
}

#endif //ADVANCED_ALGORITHMS_ACTINT_2_SRC_NODE_H_
