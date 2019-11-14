#include <iostream>

#include "Trie.h"

using namespace std;

int main() {

    Trie<string> trie;

    trie.insert("parangaricutirimicuaro", 22);
    trie.insert("parangaricutirimicua", 20);

    cout << trie.search("parangaricutirimicua") << endl;

    return 0;
}