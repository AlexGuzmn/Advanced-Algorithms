#ifndef ADVANCED_ALGORITHMS_ACTINT_2_SRC_NODE_H_
#define ADVANCED_ALGORITHMS_ACTINT_2_SRC_NODE_H_

#include <iostream>
#include <vector>
#include "Edge.h"

class Node {
 public:
  Node(int id);
  int getId();

  void addEdge(Node *, int);
  void printEdges();
  Node *getNodeInsideEdges(int);
  vector<Edge *> getEdges();
  bool isVisited();
  void setVisited(bool);
 private:
  int id = -1;
  bool visited = false;
  vector<Edge *> edges;
};

Node::Node(int id) {
  this->id = id;
}

int Node::getId() {
  return id;
}

bool Node::isVisited() {
  return visited;
}

void Node::setVisited(bool visited) {
  this->visited = visited;
}

void Node::addEdge(Node *toNode, int weight) {
  // We can't allow to add an edge to itself
  if (toNode->id == this->id) {
	cout << "Error: Can't add an edge to itself" << endl;
	return;
  }

  Edge *edge = new Edge(toNode, weight);
  edges.push_back(edge);
}

void Node::printEdges() {
  cout << "- Node " << this->id << " has " << edges.size() << " edges" << endl;
  for (int i = 0; i < edges.size(); i++) {
	cout << "  > Edge " << i << " to node " << edges[i]->getToNode()->getId() << " with weight " <<
		 edges[i]->getWeight() << endl;
  }
}

Node *Node::getNodeInsideEdges(int id) {
  for (int i = 0; i < edges.size(); i++) {
	if (edges[i]->getToNode()->getId() == id) {
	  return edges[i]->getToNode();
	}
  }
  return nullptr;
}

vector<Edge *> Node::getEdges() {
  return edges;
}

#endif //ADVANCED_ALGORITHMS_ACTINT_2_SRC_NODE_H_
