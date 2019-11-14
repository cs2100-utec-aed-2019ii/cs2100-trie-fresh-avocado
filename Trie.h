//
// Created by Gabriel Spranger Rojas on 11/13/19.
//

#ifndef TRIE_TRIE_H
#define TRIE_TRIE_H

#include "Node.h"

template <typename T>
class Trie {};

template <>
class Trie<std::string> {
    Node<char>* root;

public:
    Trie(): root{nullptr} {}

    void print() {
        // TODO
    }

    bool searchWithPrefix(const std::string& prefix) {
        // TODO
        return false;
    }

    void erase(std::string& word) {
        // TODO
    }

    bool search(const std::string& s) {
        std::map<char, Node<char>*> mapToLookIn = root->children;
        Node<char>* childAux;
        unsigned size = s.size();
        unsigned verifier = 0;
        for (unsigned i = 0; i < size; ++i)
        {
            for (auto& [letter, child] : mapToLookIn)
            {
                childAux = child;
//                std::cout << "Comparing " << letter << " to " << s[i] << std::endl;
//                if (i == size-1 && child->isWord)
//                    std::cout << "Last letter's child has isWord set to true." << std::endl;
                if (s[i] == letter) {
                    ++verifier;
                    mapToLookIn = child->children;
                    continue;
                } else {
                    return false;
                }
            }
        }
//        std::cout << "Verifier: " << verifier << std::endl;
//        std::cout << "Size: " << size << std::endl;
        return verifier == size && childAux->isWord;
    }

    void insert(const std::string& word, const unsigned& wordSize) {
        if (root) {
            if (wordSize > 1) {
                Node<char>* childOfLetter;
                std::map<char, Node<char>*> mapToLookIn = root->children;
                bool dontEnterTheInnerLoop = false;

                for (unsigned i = 0; i < wordSize; ++i)
                {
                    bool letterFound = false;
                    if (!dontEnterTheInnerLoop)
                    {
                        RestartLoop:
                        for (auto& [letter, childOfLetter] : mapToLookIn)
                        {
                            if (letter == word[i])
                            {
                                letterFound = true;
                                if (i == wordSize-1 && childOfLetter)
                                {
                                    childOfLetter->isWord = true;
                                    return;
                                }
                                else if (i == wordSize-1 && !childOfLetter)
                                {
                                    childOfLetter = new Node<char>(' ', nullptr, true);
                                }
                                else if (i != wordSize-1 && childOfLetter)
                                {
                                    mapToLookIn = childOfLetter->children;
                                }
                                else if (i != wordSize-1 && !childOfLetter)
                                {
                                    dontEnterTheInnerLoop = true;
                                    childOfLetter = new Node<char>();
                                }

                            }
                        }
                    }

                    if (!letterFound)
                    {
                        auto* node = new Node<char>();
                        mapToLookIn.insert(std::pair<char, Node<char>*>(word[i], nullptr));
                        goto RestartLoop;
                    }

                    if (dontEnterTheInnerLoop)
                    {
                        if (i == wordSize-1)
                        {
                            childOfLetter = new Node<char>(' ', nullptr, true);
                        }
                        else
                        {
                            auto* node = new Node<char>();
                            childOfLetter->children.insert(std::pair<char, Node<char>*>(word[i+1], node));
                            childOfLetter = childOfLetter->children.begin()->second;
                        }
                    }
                }

            } else {
                for (auto& [letter, childOfLetter] : root->children) {
                    if (letter == word[0]) { // encontró la letra
                        childOfLetter = new Node<char>(' ', nullptr, true);
                        return;
                    }
                }
                // no encontró la letra
                auto* node = new Node<char>(' ', nullptr, true);
                root->children.insert(std::pair<char, Node<char>*>(word[0], node));
            }
        } else {
            if (wordSize > 1) {
                auto* node = new Node<char>(word[1], nullptr, false);
                root = new Node<char>(word[0], node, false);
                for (unsigned i = 2; i < wordSize; ++i) {
                    node->children.begin()->second = new Node<char>(word[i], nullptr, false);
                    node = node->children.begin()->second;
                }
                node->children.begin()->second = new Node<char>(' ', nullptr, true);
            } else {
                auto* node = new Node<char>(' ', nullptr, true);
                root = new Node<char>(word[0], node, false);
            }
        }
    }

    ~Trie() = default; // TODO: free memory
};

#endif //TRIE_TRIE_H
