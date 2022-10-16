/*

Activity 3.3 Implementation of the Knapsack Problem

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

*/

#include <iostream>
#include <vector>
#include "src/Utils.h"

using namespace std;


int main(){
  vector< vector<int> > items;

  int n = 0; // Number of items
  int maxCapacity = 0; // Max capacity of bag

  Utils::processInput(items, n, maxCapacity);
  Utils::knapsackAlgorithm(items, n, maxCapacity);

  return 0;
}