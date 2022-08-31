/*

Activity 1.2 Implementation of the programming techniques "Dynamic programming" and "greedy algorithms"
Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

 This class contains all the auxiliar functions to solve and keep organized the coin change problem

*/

#ifndef ADVANCED_ALGORITHMS_UTILS_H
#define ADVANCED_ALGORITHMS_UTILS_H

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Utils {
    public:
        static void mergeSort(int,
                              int,
                              vector<int> &);
        static void printVectorValues(vector<int> &,
                                      string);
        static void insertMap(map<int, int> &, int);
        static void printFormattedMap(map<int, int> &);

    private:
        static void merge(int &,
                          int &,
                          vector<int> &);


};

// Print values of a Map - O(n)
void Utils::printFormattedMap(map<int, int> & coinsUsed) {
    map<int, int>::reverse_iterator itr;
    for (itr = coinsUsed.rbegin(); itr != coinsUsed.rend(); itr++) {
        cout << "$" << itr->first << " - " << itr->second << endl;
    }
}

// Print vector values - O(n)
void Utils::printVectorValues(vector<int> &vector, string msg) {
    cout << msg;
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

// Aux insert Map - O(n)
void Utils::insertMap(map<int, int> &map, int data) {
    if (map.find(data) == map.end()) {
        map[data] = 1;
    } else {
        map[data]++;
    }
}

// Auxiliar Merge Sort - O(n)
void Utils::merge(int &beg, int &end, vector<int> &unsortedVector) {
    vector<int> aux;
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
void Utils::mergeSort(int beg, int end, vector<int> &unsortedVector) {
    if (beg < end) {
        int center = (beg + end) / 2;
        mergeSort(beg, center, unsortedVector);
        mergeSort(center + 1, end, unsortedVector);
        merge(beg, end, unsortedVector);
    }
}


#endif //ADVANCED_ALGORITHMS_UTILS_H
