#include <bits/stdc++.h>
#include "trienode.hpp"
using namespace std;

template<typename T>
class trie{
    private: 
        TrieNode<T>* root;
        int capacity;

    public:
    // using iterator = trie_iterator<T>;

    // begin and end objects of template class trie_iterator
    // iterator begin();
    // iterator end();

    trie() {
        root = createNode();
        capacity = 0;
    }

    T& operator[] (string key) {
        return ((this->insertNode(key))->value);
    }

    TrieNode<T>* createNode() {
        TrieNode<T>* node = new TrieNode<T>();
        node->eow = 0;
        node->value = T();
        return node;
    }

    TrieNode<T>* insertNode(string key, T value = T()) {
        TrieNode<T>* parse = this->root;
        for(int i=0; i<key.size(); i++) {
            if(parse->next.find(key[i]) == parse->next.end()) parse->next[key[i]] = this->createNode();
            parse = parse->next[key[i]];
        }
        if(!parse->eow) this->capacity++;
        parse->eow = 1;
        return parse;
    }

    bool find(string key) {
        TrieNode<T> *parse = this->root;
        for(int i=0; i<key.size(); i++) {
            if(parse->next.find(key[i]) == parse->next.end()) return 0;
            parse = parse->next[key[i]];
        }
        return 1;
    }

    bool empty() {
        return this->root->next.empty();
    }

    TrieNode<T>* deleteNode(TrieNode<T>* root, string key, int depth = 0) {
        if (!root) return NULL;
        if (depth == key.size()) {
            if (root->eow) {this->capacity--; root->eow = 0;}
            if (root->next.empty()) {
                delete (root);
                root = NULL;
            }
            return root;
        }
        
        TrieNode<T>* temp = this->deleteNode(root->next[key[depth]], key, depth + 1);
        if(!temp) root->next.erase(key[depth]);
        else root->next[key[depth]] = temp;

        if (root->next.empty() && !root->eow) {
            delete (root);
            root = NULL;
        }
        return root;
    }

    void erase(string key) {
        deleteNode(this->root, key);
    }

    int size() {
        return this->capacity;
    }
};

// template<typename T> trie<T> :: begin()
// {

// }

// template<typename T> trie<T>::end()
// {
   
// }