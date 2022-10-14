/*

Activity 3.2 Implementation of Dijkstra and Floyd algorithms

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

This class contains all the auxiliar functions to solve and keep organized the implementation

*/

#ifndef DIJKSTRA_FLOYD_UTILS_H
#define DIJKSTRA_FLOYD_UTILS_H

#include <iostream>
#include <vector>
using namespace std;

const int limit = 99999999;

class Utils {
 public:
  static void createMtx(vector< vector<int> > &, int);
  static void printMtx(vector< vector<int> >);
  static void dijkstraFunction(vector< vector<int> >, int, int);
  static void floydFunction(vector< vector<int> >, int);
 private:
  static void setInfinity(vector< vector<int> > &, int);
  static int minDist(vector<int>&, vector<bool>&);
};

//Print Matrix - O(n^2)
void Utils::printMtx(vector< vector<int> > mtx) {
  int n = mtx.size();
  cout << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mtx[i][j] == limit){
        cout << "INF ";
      }else{
        cout << mtx[i][j] << " ";
      }
    }
	  cout << endl;
  }
  cout << endl;
}

//Set Infinity - O(n^2)
void Utils::setInfinity(vector< vector<int> > &mtx, int n) {
  for (int i = 0; i < n; i++) {
	for (int j = 0; j < n; j++) {
	  if (mtx[i][j] == -1) {
		mtx[i][j] = limit;
	  }
	}
  }
}

//Funtion that founds the minimun distance in between the unvisited nodes
//minDist - O(n)
int Utils::minDist( vector<int> &distances, vector<bool> &visitedNodes){
  int min = limit;
  int minIndex = 0;

  for (int i = 0; i < distances.size(); i++){
    if (visitedNodes[i] == false && distances[i] <= min){
      min = distances[i];
      minIndex = i;
    }
  }
  return minIndex;
}

// Funtion that uses the Dijkstra algorithm to calculate the shortest distance between nodes
// dijkstraFunction - O(V^2) where V are the number of nodes in the graph
void Utils::dijkstraFunction(vector< vector<int> > mtx, int nodes, int source) {

  vector<int> dist(nodes, limit);
  vector<bool> visited(nodes, false);

  dist[source] = 0;

  for(int i = 0; i < nodes-1; i++){
    int u = minDist(dist, visited);
    visited[u] = true;
    for (int v = 0; v < nodes; v++){
      if(!visited[v] && mtx[u][v] && dist[u] != limit && dist[u] + mtx[u][v] < dist[v] && mtx[u][v] != -1){
        dist[v] = dist[u] + mtx[u][v];
      }
    }
  }

  // Sub functon that shows the output 
  // Complexity - O(n)
  for (int i = 0; i < nodes; i++){
    if (source != i){
      if (dist[i] != limit){
        cout << "Node " << source + 1 <<  " to node " << i+1 << ": " << dist[i] << endl;
      }else{
        cout << "Node " << source + 1 <<  " to node " << i+1 << ": " << "No path found (No connection)" << endl;
      }
    }
  }
}

// Floyd Algorithm Function - O(n^3)
void Utils::floydFunction(vector< vector<int> > mtx, int n) {
  cout << "\n\n----- Floyd Algorithm -----" << endl;
  setInfinity(mtx, n);
  for (int k = 0; k < n; k++) {
	for (int i = 0; i < n; i++) {
	  for (int j = 0; j < n; j++) {
		if (mtx[i][k] + mtx[k][j] < mtx[i][j]) {
		  mtx[i][j] = mtx[i][k] + mtx[k][j];
		}
	  }
	}
  }
  printMtx(mtx);
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

#endif //DIJKSTRA_FLOYD_UTILS_H