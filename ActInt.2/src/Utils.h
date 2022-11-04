#ifndef ADVANCED_ALGORITHMS_ACTINT_2_SRC_UTILS_H_
#define ADVANCED_ALGORITHMS_ACTINT_2_SRC_UTILS_H_

#include <iostream>
using namespace std;
class Utils{
 public:
  static int** getMatrixFromInput(int *n);
  static void printMatrix(int **matrix, int *n);

};

int** Utils::getMatrixFromInput(int *n){
  int **matrix = new int*[*n];
  for (int i = 0; i < *n; i++){
	matrix[i] = new int[*n];
  }
  for (int i = 0; i < *n; i++){
	for (int j = 0; j < *n; j++){
	  cin >> matrix[i][j];
	}
  }
  return matrix;
}

void Utils::printMatrix(int **matrix, int *n) {
  for (int i = 0; i < *n; i++){
	for (int j = 0; j < *n; j++){
	  cout << matrix[i][j];
	}
	cout << endl;
  }
}


#endif