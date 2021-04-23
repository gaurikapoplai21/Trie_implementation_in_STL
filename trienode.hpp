#ifndef TRIE_NODE_H
#define TRIE_NODE_H

template<typename T>
class TrieNode{
    map<char, struct TrieNode *> next;
    T value;
    bool eow;
};

#endif

