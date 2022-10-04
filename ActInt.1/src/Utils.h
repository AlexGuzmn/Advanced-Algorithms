//
// Created by Jose Naime on 09/09/22.
//

#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <fstream>

class Utils {
    public:
        static string openFiles(string fileName);

        static string findLongestPalindrome(string str);

    private:
        static string getLongestPalindromeFromMatrix(int **str, int maxCenter, int maxLen);

};

string Utils::openFiles(string srcFile){
    string line;
    string fileContent = "";
    ifstream file(srcFile);
    if (file.is_open()) {
        while (getline(file, line)) {
            fileContent += line;
        }
        file.close();
    } else {
        cout << "Unable to open file";
    }
    return fileContent;
}

string Utils::findLongestPalindrome(string str) {
    int center = 0;
    int left = 0;
    int right = 0;
    int maxLen = 0;
    int maxCenter = 0;
    int p[str.length()];

    for (int i = 1; i < len - 1; i++) {
        int mirror = 2 * center - i;
        if (right > i) {
            p[i] = (right - i) < p[mirror] ? (right - i) : p[mirror];
        } else {
            p[i] = 0;
        }
        while (str[i + (1 + p[i])] == str[i - (1 + p[i])]) {
            p[i]++;
        }
        if (i + p[i] > right) {
            center = i;
            right = i + p[i];
        }
        if (p[i] > maxLen) {
            maxLen = p[i];
            maxCenter = i;
        }
    }

    return getLongestPalindromeFromMatrix(str, maxCenter, maxLen);
}

string Utils::getLongestPalindromeFromMatrix(int **str, int maxCenter, int maxLen) {
    string longestPalindrome = "";

    // Print the longest palindrome and add it to the string
    for (int i = maxCenter - maxLen; i <= maxCenter + maxLen; i++) {
        longestPalindrome += str[i];
        cout << str[i];
    }

    return longestPalindrome;
}

#endif //UTILS_H