//
// Created by Jose Naime on 09/09/22.
//

#ifndef UTILS_H
#define UTILS_H

#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

class Utils {
    public:
        static string openFiles(string fileName);

        static string findLongestPalindrome(string str, unsigned int *startPos, unsigned int *endPos);
        static bool isContentInFile(string fileContent, string contentToFind, unsigned int *pos);
        static void longestCommonSubstring(string string1, string string2, unsigned int *startPos, unsigned int *endPos);

    private:
        static string getLongestPalindromeFromMatrix(string str, int maxCenter,
                                                     int maxLen);
        static void computeLPSArray(string pat, int M, int *lps);
};

string Utils::openFiles(string srcFile) {
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

// KMP algorithm to verify if a string is inside another string
// Time complexity: O(n)
bool Utils::isContentInFile(string fileContent, string contentToFind, unsigned int *pos) {
    int m = contentToFind.length();
    int n = fileContent.length();

    int lps[m];
    computeLPSArray(contentToFind, m, lps);

    int j = 0;
    int i = 0;
    while (i < n) {
        if (contentToFind[j] == fileContent[i]) {
            j++;
            i++;
        }

        if (j == m) {
            *pos = i - j;
            return true;
        } else if (i < n && contentToFind[j] != fileContent[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    return false;
}

// Time complexity: O(n)
void Utils::computeLPSArray(string pat, int M, int *lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {

            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Time Complexity O(n^2)
void Utils::longestCommonSubstring(std::string string1, std::string string2, unsigned int *startPos, unsigned int *endPos) {
    int m = string1.length();
    int n = string2.length();

    int longestCommonSubstring[m + 1][n + 1];
    int longestSubstringLength = 0;

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                longestCommonSubstring[i][j] = 0;
            } else if (string1[i - 1] == string2[j - 1]) {
                longestCommonSubstring[i][j] = longestCommonSubstring[i - 1][j - 1] + 1;
                if (longestCommonSubstring[i][j] > longestSubstringLength) {
                    longestSubstringLength = longestCommonSubstring[i][j];
                    *startPos = i - longestSubstringLength;
                    *endPos = i;
                }
            } else {
                longestCommonSubstring[i][j] = 0;
            }
        }
    }
}

// Time Complexity O(n^2) as we are making a matrix of size n^2 and we are iterating over it
string Utils::findLongestPalindrome(string str, unsigned int *startPos, unsigned int *endPos) {
    unsigned int center = 0;
    unsigned int right = 0;
    unsigned int maxLen = 0;
    unsigned int maxCenter = 0;
    int p[100] = {0};

    for (int i = 1; i < str.length() - 1; i++) {
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

    *startPos = maxCenter - maxLen + 1;
    *endPos = maxCenter + maxLen + 1;

    return getLongestPalindromeFromMatrix(str, maxCenter, maxLen);
}

// Time Complexity O(n)
string Utils::getLongestPalindromeFromMatrix(string str, int maxCenter,
                                             int maxLen) {
    string res = "";

    // Print the longest palindrome and add it to the string
    for (int i = maxCenter - maxLen; i <= maxCenter + maxLen; i++) {
        res += str[i];
    }

    return res;
}

#endif // UTILS_H