
/*
ACTIVIDAD INTEGRADORA 1

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610
Vanessa M. Cuevas Arroyo - A01634064
*/

#include <iostream>
#include <map>
#include <vector>

#include "./src/Utils.h"

using namespace std;

int main() {
    map<string, string>::iterator itr;
    map<string, string> filesValues;

    filesValues["mccode1"] = Utils::openFiles(
            "/Users/jose_n/Library/Mobile Documents/com~apple~CloudDocs/Clion Projects/Actividad_Integradora_1/src/inputs/mccode1.txt");
    filesValues["mccode2"] = Utils::openFiles(
            "/Users/jose_n/Library/Mobile Documents/com~apple~CloudDocs/Clion Projects/Actividad_Integradora_1/src/inputs/mccode2.txt");
    filesValues["mccode3"] = Utils::openFiles(
            "/Users/jose_n/Library/Mobile Documents/com~apple~CloudDocs/Clion Projects/Actividad_Integradora_1/src/inputs/mccode3.txt");
    filesValues["transmission1"] = Utils::openFiles(
            "/Users/jose_n/Library/Mobile Documents/com~apple~CloudDocs/Clion Projects/Actividad_Integradora_1/src/inputs/transmission1.txt");
    filesValues["transmission2"] = Utils::openFiles(
            "/Users/jose_n/Library/Mobile Documents/com~apple~CloudDocs/Clion Projects/Actividad_Integradora_1/src/inputs/transmission2.txt");

    /*
     * Ejericio 1:
     */

    cout << "\n------ Ejercicio 1" << endl;

    for (itr = filesValues.begin(); itr != filesValues.end(); ++itr) {
        if (itr->first.find("mccode") != string::npos) {
            unsigned int pos1 = 0;
            unsigned int pos2 = 0;

            string isInTransmission1 = Utils::isContentInFile(filesValues["transmission1"], itr->second, &pos1) ? "true"
                                                                                                                : "false";
            string isInTransmission2 = Utils::isContentInFile(filesValues["transmission2"], itr->second, &pos2) ? "true"
                                                                                                                : "false";
            cout << itr->first << endl;
            cout << isInTransmission1 << " - " << "transmission1" << "\t" << pos1 << "\t" << itr->second << endl;
            cout << isInTransmission2 << " - " << "transmission2" << "\t" << pos2 << "\t" << itr->second << endl;
            cout << endl;
        }
    }

    /*
     * Ejercicio 2
     */

    cout << "\n------ Ejercicio 2" << endl;

    for (itr = filesValues.begin(); itr != filesValues.end(); ++itr) {
        unsigned int startPos = 0;
        unsigned int endPos = 0;
        cout << itr->first << " - " << Utils::findLongestPalindrome(itr->second, &startPos, &endPos) << " - Pos: " << startPos << " " << endPos<< endl;

    }

    /*
     * Ejercicio 3
     */
    cout << "\n------ Ejercicio 3" << endl;
    unsigned int startPos = 0;
    unsigned int endPos = 0;
    Utils::longestCommonSubstring(filesValues["transmission1"], filesValues["transmission2"], &startPos, &endPos);
    cout << startPos << " " << endPos << endl;






    return 0;
}