#include <iostream>
#include <vector>
#include "src/Utils.h"

using namespace std;

/*
  items:
  [Value, Weight]
 */

int main(){
  vector< vector<int> > items;

  int n = 0; // Number of items
  int maxCapacity = 0; // Max capacity of bag

  Utils::processInput(items, n, maxCapacity);
  Utils::knapsackAlgorithm(items, n, maxCapacity);





  return 0;
}