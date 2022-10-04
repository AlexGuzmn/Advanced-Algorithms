#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

void findLongestPalindrome(char *str, int *p, int *maxLen, int *maxCenter) {
    int len = strlen(str);
    int center = 0;
    int right = 0;
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
        if (p[i] > *maxLen) {
            *maxLen = p[i];
            *maxCenter = i;
        }
    }
}

int main(int argc, char *argv[])
{
    char str[100];
    int p[100];
    int maxLen = 0;
    int maxCenter = 0;
    printf("Enter a string: ");
    scanf("%s", str);
    findLongestPalindrome(str, p, &maxLen, &maxCenter);

    // Print the longest palindrome
    for (int i = maxCenter - maxLen; i <= maxCenter + maxLen; i++) {
        cout << str[i];
    }

    return 0;
}