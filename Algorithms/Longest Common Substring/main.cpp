#include <iostream>
#include <string>

using namespace std;

void printMatrix(int **matrix, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    string str1 = "AGGTAB";
    string str2 = "BCTGTA";

    const int rows = str1.length() + 1;
    const int columns = str2.length() + 1;

    int mtx[rows][columns];

    cout << rows << " " << columns << endl;


    return 0;
}