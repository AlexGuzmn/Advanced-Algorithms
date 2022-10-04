/*

Andrés Alejandro Guzmán González - A01633819
José Pablo Naime García - A01367610

*/

#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    char letter;
    bool isWord;
    unordered_map<char, Node *> children;

    Node(char letter) {
        this->letter = letter;
        this->isWord = false;
    }
};

class Trie {
    public:
        Trie();
        void insert(string word);
        bool search(string word);
        void dfs(string word);
        void printChildrenOfNode(Node *node);
        Node *getRoot();

    private:
        Node *root;
};

Trie::Trie() {
    root = new Node(' ');
}

Node *Trie::getRoot() {
    return root;
}

void Trie::insert(string word) {
    Node *current = root;
    for (int i = 0; i < word.length(); i++) {
        char letter = word[i];
        Node *node = current->children[letter];
        if (node == NULL) {
            node = new Node(letter);
            current->children[letter] = node;
        }
        current = node;
    }
    current->isWord = true;
}

void Trie::printChildrenOfNode(Node *node) {
    for (auto it = node->children.begin(); it != node->children.end(); it++) {
        cout << it->first << " ";
    }
    cout << endl;
}

bool Trie::search(string word) {
    cout << word << " - ";

    Node *current = root;
    for (int i = 0; i < word.length(); i++) {
        char letter = word[i];
        Node *nextNode = current->children[letter];

        if (current->children.empty() || nextNode == NULL) {
            return false;
        } else {
            current = nextNode;
        }
    }
    return current->isWord;
}

void Trie::dfs(string word) {
    cout << "  CURRENT | CHILDREN" << endl;
    Node* current = root;
    for (int i = 0; i < word.length(); i++){
        char letter = word[i];
        Node *nextNode = current->children[letter];
        cout << i << ".   " << current->letter << "   ->   ";
        printChildrenOfNode(current);

        if (current->children.empty() || nextNode == NULL) {
            break;
        } else {
            current = nextNode;
        }
    }
}

#endif //TRIE_H