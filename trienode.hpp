#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <bits/stdc++.h>
using namespace std;

template<typename T>
class TrieNode{
    public:
        map<char, TrieNode<T>*> next;
        // char key;
        T value;
        bool eow;
};

#endif