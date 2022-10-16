/*

Activity 3.4 Implementation of Graph coloring

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

This class contains all the auxiliar functions to solve and keep organized the implementation

*/

#ifndef GRAPH_COLORING_UTILS_H
#define GRAPH_COLORING_UTILS_H

#include <iostream>
#include <vector>

class Utils {
 private:
  static void printResult(vector<int>);
 public:
  static void createMtx(vector< vector<int> > &, int);
  static void printMtx(vector< vector<int> >);
  static void graphColoring(vector< vector<int> > &, int);
};

//Print Matrix - O(n^2)
void Utils::printMtx(vector< vector<int> > mtx) {
  int n = mtx.size();
  cout << endl;
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  cout << mtx[i][j] << " ";
	}
	cout << endl;
  }
  cout << endl;
}

// Create Matrix - O(n^2)
void Utils::createMtx(vector< vector<int> > &mtx, int n) {
  int data;
  for (int i = 0; i < n; i++) {
	vector<int> aux;
	for (int j = 0; j < n; j++) {
	  cin >> data;
	  aux.push_back(data);
	}
	mtx.push_back(aux);
  }
}

// printResult O(n)
void Utils::printResult(vector<int> vec) {
  for (int i = 0; i < vec.size(); i++) {
	cout << "Node: " << i << ", Assigned Color: " << vec[i] << endl;
  }
}

// graphColoring O(V^2 + E)
void Utils::graphColoring(vector< vector<int> > &mtx, int n) {
  vector<int> colors(n, 0);
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if (mtx[i][j] == 1 && colors[i] == colors[j]) {
		colors[j] += 1;
	  }
	}
  }
  printResult(colors);
}

#endif //GRAPH_COLORING_UTILS_H