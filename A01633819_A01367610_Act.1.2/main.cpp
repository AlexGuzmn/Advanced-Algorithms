#include <iostream>
#include <vector>
#include <map>
using namespace std;

//// Auxiliar function to print vector values - O(n)
void printVectorValues(vector<int> &vector, string msg) {
    cout << msg;
    for (int i = 0; i < vector.size(); i++) {
        cout << vector[i] << " ";
    }
    cout << endl;
}

// Auxiliar Merge Sort - O(n)
void merge(int &beg, int &end, vector<int> &unsortedVector) {
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
void mergeSort(int beg, int end, vector<int> &unsortedVector) {
    if (beg < end) {
        int center = (beg + end) / 2;
        mergeSort(beg, center, unsortedVector);
        mergeSort(center + 1, end, unsortedVector);
        merge(beg, end, unsortedVector);
    }
}

// Aux insert Map O(n)
void insertMap(map<int, int> &map, int data){
    if (map.find(data) == map.end()){
        map[data] = 1;
    }else{
        map[data]++;
    }

}


void greedy(vector<int> denom, int change){
    map<int, int> ans;
    int i = 0;
    while(change !=0 ){
        if(denom[i] <= change){
            change -= denom[i];
            insertMap(ans, denom[i]);
        }else{
            i++;
        }
    }
    map<int, int>::reverse_iterator itr;
    for (itr = ans.rbegin(); itr != ans.rend(); itr++){
        cout << "$" << itr->first << " - " << itr->second << endl;
    }


}


int main(){
    int nDemoninations, price, payment, aux, change;
    vector<int> denominations;

    cin >> nDemoninations;
    for (int i = 0; i < nDemoninations; i++){
        cin >> aux;
        denominations.push_back(aux);
    }
    mergeSort(0, (nDemoninations - 1), denominations);
    cin >> price;
    cin >>  payment;
    printVectorValues(denominations, "Denominations: ");
    cout << endl;
    change = payment - price;
    try{
        if (change >= 1){
            cout << "The change is $" << change << endl;
            cout << "\n--------------------------" << endl;
            cout << "Dynamic Algoritm Solution\n" << endl;
            // Call Dynamic Function
            cout << "--------------------------" << endl;
            cout << "Greedy Algoritm Solution\n" << endl;
            greedy(denominations, change);
            cout << "--------------------------" << endl;

        }else if(change == 0){
            cout << "\n The payment is exact, there is no change to give.\n" << endl;
        }else{
            throw(change);
        }
    }
    catch(int num){
        cout << "\n There is not enough money for the payment" << endl;
        cout << " Change = $" << num << endl;
        cout << endl;
    }

    return 0;
}

/*








*/