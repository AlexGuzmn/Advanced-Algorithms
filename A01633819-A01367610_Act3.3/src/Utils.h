//
// Created by Jose Naime on 14/10/22.
//

#ifndef ADVANCED_ALGORITHMS_A01633819_A01367610_ACT3_3_SRC_UTILS_H_
#define ADVANCED_ALGORITHMS_A01633819_A01367610_ACT3_3_SRC_UTILS_H_

#include <iostream>
#include <vector>

using namespace std;

class Utils {
 public:
  static void processInput(vector<vector<int>> &items, int &n, int &maxCapacity);
  static void knapsackAlgorithm(vector<vector<int>> &items, int &n, int &maxCapacity);

};

void Utils::processInput(vector<vector<int>> &items, int &n, int &maxCapacity) {
  // Number of items
  cin >> n;

  // Read values from input
  for (int i = 0; i < n; i++) {
	int val = 0;
	cin >> val;
	vector<int> item;
	item.push_back(val);
	items.push_back(item);
  }

  // Read weights from input
  for (int i = 0; i < n; i++) {
	int w = 0;
	cin >> w;
	items[i].push_back(w);
  }

  // Read MAX capacity
  cin >> maxCapacity;

  // Sort items by weight
  sort(items.begin(), items.end(), [](const vector<int> &a, const vector<int> &b) -> bool { return a[1] < b[1]; });

  // Print items
  cout << "Items --------------" << endl;
  cout << "i\tVal Weight" << endl;
  for (int i = 0; i < n; i++) {
	cout << i + 1 << ".\t(" << items[i][0] << " , " << items[i][1] << ")" << endl;
  }
}

/*
 * n: Number of items
 * maxCapacity: Max capacity of bag
 * items: [Value, Weight]
 */
void Utils::knapsackAlgorithm(vector<vector<int>> &items, int &n, int &maxCapacity) {

  int rows = maxCapacity + 1;
  int cols = n + 1;

  cout << rows << " " << cols << endl;

  vector<vector<int> > mtx(rows, vector<int>(cols));
  cout << ":D";

  ///
  /// Fill initial values of matrix equals 0
  ///

  for (int w = 0; w <= maxCapacity; w++) {
	cout << w << " ";
	mtx[0][w] = 0;
  }

  for (int i = 0; i <= n; i++) {
	mtx[i][0] = 0;

	for (int w = 1; w <= maxCapacity; w++) {
	  int wi = items[i - 1][1];
	  int vi = items[i - 1][0];

	  if (wi <= w) {
		if (vi + mtx[i - 1][w - wi] > mtx[i - 1][w]) {
		  mtx[i][w] = vi + mtx[i - 1][w - wi];
		} else {
		  mtx[i][w] = mtx[i - 1][w];
		}
	  } else {
		mtx[i][w] = mtx[i - 1][w];
	  }
	}
  }

  /*
  cout << "Knapsack Matrix --------------" << endl;
  for (int i = 0; i <= n; i++) {
	for (int w = 0; w <= maxCapacity; w++) {
	  cout << mtx[i][w] << " ";
	}
	cout << endl;
  }

  // Answer
  cout << "\nAnswer --------------" << endl;
  cout << "Max value: " << mtx[n][maxCapacity] << endl;*/

}

#endif //ADVANCED_ALGORITHMS_A01633819_A01367610_ACT3_3_SRC_UTILS_H_
