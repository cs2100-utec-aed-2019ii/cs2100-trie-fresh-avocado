#include <iostream>

#include "Trie.h"

using namespace std;

int main() {

    Trie<string> trie;

    trie.insert("parangaricutirimicuaro");
    trie.insert("pola");
    trie.insert("alaraco");
    trie.insert("alharaco");

    cout << "-----------\n";
    cout << "Letters in root\n";
    cout << "-----------\n";
    for (auto& [letter, child]: trie.root->children)
        cout << letter << "\n";
    cout << "-----------\n";

    cout << "SearchWord and SearchPrefix\n";
    cout << "-----------\n";
    cout << trie.searchWord("parangaricutirimicua") << endl;
    cout << trie.searchPrefix("pol") << endl;

    cout << "-----------\n";
    cout << "Print\n";
    cout << "-----------\n";
    trie.print();

    return 0;
}