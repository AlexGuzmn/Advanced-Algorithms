/*

Activity 1.1 Implementation of the tecnic Divide and Conquer
Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

*/

#include <iostream>
#include <vector>

using namespace std;

// Auxiliar function to print vector values - O(n)
void printVectorValues(vector<double> &vector, string msg) {
    cout << msg;
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

// Auxiliar Merge Sort - O(n)
void merge(double &beg, double &end, vector<double> &unsortedVector) {
    vector<double> aux;
    int center = (beg + end) / 2,
            j = beg,
            k = center + 1,
            size = end - beg + 1;
    for (int i = 0; i < size; i++) {
        if (j <= center && k <= end) {
            //
            if (unsortedVector[j] > unsortedVector[k]) {
                aux.push_back(unsortedVector[j++]);
            } else {
                aux.push_back(unsortedVector[k++]);
            }
        } else if (j <= center) {
            aux.push_back(unsortedVector[j++]);
        } else {
            aux.push_back(unsortedVector[k++]);
        }
    }
    for (int i = 0; i < size; i++) {
        unsortedVector[beg + i] = aux[i];
    }
}

// MergeSort O(n log n)
void mergeSort(double beg, double end, vector<double> &unsortedVector) {
    if (beg < end) {
        double center = (beg + end) / 2;
        mergeSort(beg, center, unsortedVector);
        mergeSort(center + 1, end, unsortedVector);
        merge(beg, end, unsortedVector);
    }
}

int main() {
    vector<double> valuesToSort;
    double num;

    int vectorSize = 0;

    // Get first value of input as the vector size
    cin >> vectorSize;

    // Get numbers from file and store them into a vector - O(n)
    while (valuesToSort.size() < vectorSize) {
        cin >> num;
        valuesToSort.push_back(num);
    }

    // Check if there was an input
    if (vectorSize == 0 || valuesToSort.empty()) {
        cout << "No input received, finishing program..." << endl;
        return 1;
    }

    // Shows the values in the input order
    printVectorValues(valuesToSort, "Unsorted Vector: ");
    cout << "Size: " << valuesToSort.size() << endl;
    mergeSort(0, (valuesToSort.size() - 1), valuesToSort);
    // Shows the values in order
    printVectorValues(valuesToSort, "Sorted Vector: ");

    return 0;
}
