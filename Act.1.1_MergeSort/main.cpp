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

void mergeSort(vector<int>& unsortedVector){

}

int main(){
    vector<int> valuesToSort;

    int num;

    // Get numbers from file and store them into a vector - O(n)
    while (cin >> num){
        valuesToSort.push_back(num);
    }

    printVectorValues(valuesToSort, "Vector: ");
}
