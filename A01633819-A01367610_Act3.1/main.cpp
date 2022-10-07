/*
Activity 3.1 - Tries Implementation

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

*/
#include <iostream>
#include "src/Trie.h"

using namespace std;
int main(){
    Trie trie = Trie();

    int wordsToEnter = 0;
    int wordsToSearch = 0;

    cin >> wordsToEnter;

    string auxWord;

    for (int i = 0; i < wordsToEnter; i++){
        cin >> auxWord;
        trie.insert(auxWord);
    }

    cin >> wordsToSearch;

    for (int i = 0; i < wordsToSearch; i++){
        cin >> auxWord;
        cout << trie.search(auxWord) << endl;
        trie.dfs(auxWord);
        cout << "\n";
    }

    return 0;
}
