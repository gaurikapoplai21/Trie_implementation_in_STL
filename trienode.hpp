#ifndef TRIE_NODE_H
#define TRIE_NODE_H
#include <bits/stdc++.h>
using namespace std;

template<typename T>
struct TrieNode{
    map<char, struct TrieNode<T> *> next;
    T value;
    bool eow;
};

#endif

