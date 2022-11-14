#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

#include "./src/Utils.h"

int main(){
    int n; //Number to search
    string values; 
    vector<int> data;
    
    getline(cin, values);
    cin >> n;
   
    Utils::makeDataVec(data, values);
    
    sort(data.begin(), data.end());
    cout << endl;
    Utils::printVec(data);
    Utils::lasVegasBinarySearch(data, n);


    return 0;
}