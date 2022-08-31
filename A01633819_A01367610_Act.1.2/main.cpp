/*

Activity 1.2 Implementation of the programming techniques "Dynamic programming" and "greedy algorithms"
Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

*/

#include <iostream>
#include <vector>
#include <map>
#include "./src/Utils.h"

using namespace std;

// Dynamic Programming function O( )
void dynamicCoinChangeProblem(int coins[], int size, int change) {
    int minCoins[change + 1];
    int lastCoin[change + 1];
    minCoins[0] = 0;
    lastCoin[0] = 0;
    for (int i = 1; i <= change; i++) {
        minCoins[i] = 999999;
        lastCoin[i] = -1;
        for (int j = 0; j < size; j++) {
            if (coins[j] <= i) {
                if (minCoins[i - coins[j]] + 1 < minCoins[i]) {
                    minCoins[i] = minCoins[i - coins[j]] + 1;
                    lastCoin[i] = j;
                }
            }
        }
    }
    int i = change;
    map<int, int> coinsUsed;
    while (i > 0) {
        Utils::insertMap(coinsUsed, coins[lastCoin[i]]);
        i = i - coins[lastCoin[i]];
    }
    Utils::printFormattedMap(coinsUsed);
}

// Greedy function O(n*m)
void greedyCoinChangeProblem(int change, vector<int> &coinsDenominations) {
    map<int, int> coinsUsed;
    int i = 0;
    try{
    while (change != 0) {
        if (coinsDenominations[i] <= change) {
            change -= coinsDenominations[i];
            Utils::insertMap(coinsUsed, coinsDenominations[i]);
        } else {
            if (i == coinsDenominations.size() - 1 ) {
                throw "The change can not be given";
            }
            i++;
        }
    }
    } catch (...){
        cout << "The change can not be returned with the given denominations." << endl;
    }
    Utils::printFormattedMap(coinsUsed);
}

int main() {
    int numOfDenominations;
    int price;
    int payment;
    int auxCin;
    int change;
    vector<int> denominations;

    // Reads the total amount of coin denominations
    cin >> numOfDenominations;

    // Reads each coin denomination
    for (int i = 0; i < numOfDenominations; i++) {
        cin >> auxCin;
        denominations.push_back(auxCin);
    }

    // Sorts all coins denominations
    Utils::mergeSort(0, (numOfDenominations - 1), denominations);

    cin >> price; // Reads price
    cin >> payment; // Reads payment

    Utils::printVectorValues(denominations, "Denominations: ");

    change = payment - price;

    try {
        if (change >= 1) {
            cout << "The change is $" << change << "\n--------------------------\n" << "Dynamic Algoritm Solution\n"
                 << endl;
            dynamicCoinChangeProblem(&denominations[0], denominations.size(), change);

            cout << "--------------------------\nGreedy Algoritm Solution\n" << endl;
            greedyCoinChangeProblem(change, denominations);
            cout << "--------------------------" << endl;

        } else if (change == 0) {
            cout << "\n The payment is exact, there is no change to give.\n" << endl;
        } else {
            throw (change);
        }
    }
    catch (int num) {
        cout << "\n There is not enough money for the payment" << "\nChange = $" << num << endl;
    }

    return 0;
}