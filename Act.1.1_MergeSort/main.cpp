/*

Activity 1.1 Implementation of the tecnic Divide and Conquer
Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Auxiliar function to print vector values - O(n)
void printVectorValues(vector<int>& vector, string msg){
    cout << msg;
    for (int i = 0; i < vector.size(); i++){
        cout << vector[i] << " ";
    }
    cout << endl;
}

// Merge Sort 
void merge(int &beg, int &end, vector<int> &unsortedVector){
    vector<int> aux;
    int center = (beg + end)/2,
        j = beg,
        k = center + 1, 
        size = end - beg + 1;
    for (int i = 0; i < size; i++){
        if (j <= center && k <= end){
            if(unsortedVector[j] < unsortedVector[k]){
                aux.push_back(unsortedVector[j++]);
            }else{
                aux.push_back(unsortedVector[k++]);               
            }
        }
        else if(j <= center){
            aux.push_back(unsortedVector[j++]);
        }else{
            aux.push_back(unsortedVector[k++]);
        }

    }
    for(int i = 0; i < size; i++){
        unsortedVector[beg + i] = aux[i];
    }


}

void mergeSort(int beg, int end, vector<int> &unsortedVector){
    if(beg < end){
        int center = (beg + end)/2;
        mergeSort(beg, center, unsortedVector);
        mergeSort(center + 1, end, unsortedVector);
        merge(beg, end, unsortedVector);
    }
}


int main(){
    vector<int> valuesToSort;
    int num;

    // Get numbers from file and store them into a vector - O(n)
    while (cin >> num){
        valuesToSort.push_back(num);
    }
    // Shows the values in the input order
    printVectorValues(valuesToSort, "Unsorted Vector: ");
    cout << "Size: " << valuesToSort.size() << endl;
    mergeSort(0, (valuesToSort.size()-1), valuesToSort);
    // Shows the values in order
    printVectorValues(valuesToSort, "Sorted Vector: ");
}
