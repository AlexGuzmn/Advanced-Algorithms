/*

Activity 3.2 Implementation of Dijkstra and Floyd algorithms

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

This class contains all the auxiliar functions to solve and keep organized the implementation

*/

#ifndef DIJKSTRA_FLOYD_UTILS_H
#define DIJKSTRA_FLOYD_UTILS_H

#include <iostream>
#include <vector>

using namespace std;

class Utils{
    public:
        static void createMtx(vector<vector<int>> &, int);
        static void printMtx(vector<vector<int>>);
        static void dijkstraFunction(vector<vector<int>>, int);
        static void floydFunction(vector<vector<int>>, int);
    private:
        static void setInfinity(vector<vector<int>> &, int);
};


//Print Matrix - O(n^2)
void Utils::printMtx(vector<vector<int>> mtx){
    int n = mtx.size();
    cout << endl;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

//Set Infinity - O(n^2)
void Utils::setInfinity(vector<vector<int>> &mtx, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (mtx[i][j] == -1){
                mtx[i][j] = 99999999;
            }
        }
    }
}

void Utils::dijkstraFunction(vector<vector<int>> mtx, int n){
    cout << "\n---------- Dijkstra Algorithm ----------" << endl;
    
}

// Floyd Algorithm Function - O(n^3)
void Utils::floydFunction(vector<vector<int>> mtx, int n){
    cout << "\n\n----- Floyd Algorithm -----" << endl;
    setInfinity(mtx, n);
    for (int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (mtx[i][k] + mtx[k][j] < mtx [i][j]){
                    mtx[i][j] = mtx[i][k] + mtx[k][j];
                }
            }
        }
    }
    printMtx(mtx);

}

// Create Matrix - O(n^2)
void Utils::createMtx(vector<vector<int>> &mtx, int n){
    int data;
    for (int i = 0; i < n; i++ ){
        vector<int> aux;
        for(int j = 0; j < n; j++){
            cin >> data;
            aux.push_back(data);
        }
        mtx.push_back(aux);
    }
}



#endif //DIJKSTRA_FLOYD_UTILS_H