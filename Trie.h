//
// Created by Gabriel Spranger Rojas on 11/13/19.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include <queue>
#include "Node.h"

template <typename T>
class Trie {};

template <>
class Trie<std::string> {
public:
    Node<char>* root;

public:
    Trie(): root{new Node<char>()} {}

    void print() {
        std::queue<Node<char>*> q;

        if (root)
            q.push(root);
        else
            return;

        while (!q.empty()) {
            unsigned nodos = q.size();

            while (nodos > 0) {
                Node<char>* n = q.front();

                for (auto& [letter, child] : n->children) {
                    std::cout << letter << " ";
                    if (child) {
                        q.push(child);
                    }
                }

                q.pop();

                --nodos;
            }
            std::cout << std::endl;

        }

    }

    void erase(std::string& word) {

    }

    bool searchPrefix(const std::string& prefix) {
        std::map<char, Node<char>*> mapToLookIn = root->children;
        Node<char>* childAux;
        unsigned size = prefix.size();
        unsigned verifier = 0;
        for (unsigned i = 0; i < size; ++i) {
            for (auto& [letter, child] : mapToLookIn)  {
                childAux = child; // es posible que child sea nullptr?
                if (letter == prefix[i]) {
                    ++verifier;
                    mapToLookIn = child->children;
                }
            }
        }
        return verifier == size && !childAux->isWord;
    }

    bool searchWord(const std::string& s) {
        std::map<char, Node<char>*> mapToLookIn = root->children;
        Node<char>* childAux;
        unsigned size = s.size();
        unsigned verifier = 0;
        for (char l : s)
        {
            for (auto& [letter, child] : mapToLookIn)
            {
                childAux = child;
                if (l == letter) {
                    ++verifier;
                    mapToLookIn = child->children;
                    continue;
                } else {
                    return false;
                }
            }
        }
        return verifier == size && childAux->isWord;
    }

    void insert(const std::string& word) {
        Node<char>* node = root;
        for (char letter : word) {
            if (node->children.count(letter)) { // si se encontró la letra
                node = node->children.at(letter); // sigue buscando
            } else { // si no se encontró
                node->children.insert(std::pair<char, Node<char>*>(letter, new Node<char>())); // insert the letter and its child
                node = node->children.at(letter); // set the map to look in to the new child's map
            }
        }
        node->isWord = true;
    }

    ~Trie() = default; // TODO: free memory
};

#endif //TRIE_TRIE_H
