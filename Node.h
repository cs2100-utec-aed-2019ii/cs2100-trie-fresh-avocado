//
// Created by Gabriel Spranger Rojas on 11/13/19.
//

#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <iostream>
#include <map>

template <typename T>
struct Node {};

template <>
struct Node<char> {
    bool isWord;
    std::map<char, Node<char>*> children;

public:
    Node(): isWord{false} {}
    Node(const char& letter, Node<char>* child, const bool& isWord): isWord{isWord} {
        std::pair<char, Node<char>*> p = std::pair<char, Node<char>*>(letter, child);
        children.insert(p);
    }
};

template <>
struct Node<std::string> {};


#endif //TRIE_NODE_H
