#include "src/Trie.h"

int main(){
    Trie trie = Trie();

    trie.insert("exam");
    trie.insert("example");
    trie.insert("fail");
    trie.insert("false");
    trie.insert("tree");
    trie.insert("true");
    trie.insert("trie");
    trie.insert("tries");
    trie.insert("trident");


    cout << trie.search("exam") << endl;
    trie.dfs("exam");

    cout << "\n\n" <<  trie.search("tries") << endl;
    trie.dfs("tries");

    cout << "\n\n" <<  trie.search("traitor") << endl;
    trie.dfs("traitor");

    return 0;
}
