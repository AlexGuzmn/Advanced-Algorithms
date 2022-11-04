#include <iostream>

using namespace std;

#include "src/classes/Node.h"
#include "src/Utils.h"

int main(){
  int n;
  cin >> n;

  int** distanceMtx = Utils::getMatrixFromInput(&n);

  Utils::printMatrix(distanceMtx, &n);


  return 0;
}