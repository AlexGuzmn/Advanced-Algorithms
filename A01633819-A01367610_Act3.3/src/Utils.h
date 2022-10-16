/*

Activity 3.3 Implementation of the Knapsack Problem

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

This class contains all the auxiliar functions to solve and keep organized the implementation

*/

#ifndef ADVANCED_ALGORITHMS_A01633819_A01367610_ACT3_3_SRC_UTILS_H_
#define ADVANCED_ALGORITHMS_A01633819_A01367610_ACT3_3_SRC_UTILS_H_

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Utils{
	public:
		static void processInput(vector<vector<int>> &items, int &n, int &maxCapacity);
		static void knapsackAlgorithm(vector<vector<int>> &items, int &n, int &maxCapacity);
};

// procesInput - O(nlog(n)) - This complexity is taken by the sorting algorithm.
// The process to store the inputs is linear - O(n)
void Utils::processInput(vector<vector<int>> &items, int &n, int &maxCapacity){
	// Number of items
	int val, w;
	cin >> n;

	// Read values from input
	for (int i = 0; i < n; i++){
		cin >> val;
		vector<int> item;
		item.push_back(val);
		items.push_back(item);
	}

	// Read weights from input
	for (int i = 0; i < n; i++)	{
		cin >> w;
		items[i].push_back(w);
	}

	// Read MAX capacity
	cin >> maxCapacity;

	// Sort items by weight
	sort(items.begin(), items.end(), [](const vector<int> &a, const vector<int> &b) -> bool
		 { return a[1] < b[1]; });

	// Print items
	cout << "\nItems --------------" << endl;
	cout << "i\tVal Weight" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i + 1 << ".\t(" << items[i][0] << " , " << items[i][1] << ")" << endl;
	}
}

// knapsackAlgorithm - O(W*n) where W is the maximum weight and n is the number of items
/*
 * n: Number of items
 * maxCapacity: Max capacity of bag
 * items: [Value, Weight]
 */
void Utils::knapsackAlgorithm(vector<vector<int>> &items, int &n, int &maxCapacity)
{

	int rows = maxCapacity + 1;
	int cols = n + 1;

	vector<vector<int>> mtx(rows, vector<int>(cols, 0));

	///
	/// Fill initial values of matrix equals 0
	///

	for(int i = 1; i < cols; i++){
		for (int w = 1; w <= maxCapacity; w++){
			int wi = items[i-1][1];
			int vi = items[i-1][0];

			if (wi <= w){
				if (vi + mtx[w - wi][i - 1] > mtx[w][i - 1]){
					mtx[w][i] = vi + mtx[w - wi][i - 1];
				}
				else{
					mtx[w][i] = mtx[w][i - 1];
				}
			}else{
				mtx[w][i] = mtx[w][i-1];
			}
		}
	}

	cout << "\nKnapsack Matrix --------------" << endl;
	for(int i = 0; i < rows ; i++){
		for (int j = 0;j < cols; j++){
			cout << mtx[i][j] << "  ";
		}
		cout << endl;
	}

	// Answer
	cout << "\nAnswer --------------" << endl;
	cout << "Max value: " << mtx[maxCapacity][n] << endl;
}

#endif // ADVANCED_ALGORITHMS_A01633819_A01367610_ACT3_3_SRC_UTILS_H_
