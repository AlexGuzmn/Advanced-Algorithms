#ifndef ADVANCED_ALGORITHMS_ACTINT_2_SRC_UTILS_H_
#define ADVANCED_ALGORITHMS_ACTINT_2_SRC_UTILS_H_

#include <iostream>
#include <map>
#include "./classes/Node.h"

using namespace std;
class Utils {
 public:
  static Utils *getInstance();

  // Matrix
  void setMatrixSize(int *n);
  int **getMatrixFromInput();
  void printMatrix(int **matrix);

  // Map
  map<int, Node *> getMapFromMatrix(int **matrix);
  static void printNodesMap(map<int, Node *> *map);

 private:
  static Utils *instance;
  int matrixSize = 0;
};

Utils *Utils::instance = nullptr;

Utils *Utils::getInstance() {
  if (!instance) instance = new Utils();
  return instance;
}

// Matrix
void Utils::setMatrixSize(int *n) {
  matrixSize = *n;
}

int **Utils::getMatrixFromInput() {
  int **m = new int *[matrixSize];
  for (int i = 0; i < matrixSize; i++) {
	m[i] = new int[matrixSize];
  }
  for (int i = 0; i < matrixSize; i++) {
	for (int j = 0; j < matrixSize; j++) {
	  cin >> m[i][j];
	}
  }
  return m;
}

void Utils::printMatrix(int **m) {
  for (int i = 0; i < matrixSize; i++) {
	for (int j = 0; j < matrixSize; j++) {
	  cout << m[i][j] << " ";
	}
	cout << endl;
  }
}

// Map
map<int, Node *> Utils::getMapFromMatrix(int **m) {
  map < int, Node * > auxMap;

  for (int i = 0; i < matrixSize; i++) {
	auto it = auxMap.find(i);

	Node *newNode;

	// Check if node doesn't exist already
	if (!auxMap.contains(i)) {
	  // Init root node
	  newNode = new Node(i);
	} else {
	  newNode = it->second;
	}

	for (int j = 0; j < matrixSize; j++) {
	  if (m[i][j] != 0) {
		auto it = auxMap.find(j);
		Node *toNode;

		if (!auxMap.contains(j)) {
		  toNode = new Node(j);
		  auxMap.insert(pair<int, Node *>(j, toNode));
		} else {
		  toNode = it->second;
		}
		newNode->addEdge(toNode, m[i][j]);
	  }
	}
	auxMap.insert(pair<int, Node *>(i, newNode));
  }
  return auxMap;
}

void Utils::printNodesMap(map<int, Node *> *map) {
  for (auto it = map->cbegin(); it != map->cend(); ++it) {
	cout << it->first;
	it->second->printEdges();
  }
}

#endif