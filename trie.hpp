#include <bits/stdc++.h>
#include "trienode.hpp"
#include "trie_iterator.hpp"
using namespace std;
#define SIZE 26

template<typename T>
class trie{
    private: 
        TrieNode* root;

    public:
    

    using iterator = trie_iterator<T>;

    //begin and end objects of template class trie_iterator
    iterator begin();
    iterator end();


    trie() {
        root = createNode();
    }

    int& operator[] (string key) {
        return ((this->insertNode(key))->value);
    }

    TrieNode* createNode() {
        TrieNode* node = new TrieNode;
        node->eow = 0;
        node->value = 0;
        return node;
    }

    TrieNode* insertNode(string key, int value = 0) {
        TrieNode *parse = this->root;
        for(int i=0; i<key.size(); i++) {
            if(parse->next.find(key[i]) == parse->next.end()) parse->next[key[i]] = this->createNode();
            parse = parse->next[key[i]];
        }
        parse->eow = 1;
        return parse;
    }

    bool find(string key) {
        TrieNode *parse = this->root;
        for(int i=0; i<key.size(); i++) {
            if(parse->next.find(key[i]) == parse->next.end()) return 0;
            parse = parse->next[key[i]];
        }
        return 1;
    }

    bool empty() {
        for(auto a:this->root->next) {
            cout << a.first << " ";
        }
        cout << endl;
        return this->root->next.empty();
    }

    bool isEmptyNode(TrieNode *root) {
        cout << root->next.empty() << endl;
        return root->next.empty();
    }

    TrieNode* deleteNode(TrieNode* root, string key, int depth = 0) {
        if (!root) return NULL;
        if (depth == key.size()) {
            if (root->eow) root->eow = 0;
            if (root->next.empty()) {
                delete (root);
                root = NULL;
            }
            return root;
        }
        
        TrieNode* temp = this->deleteNode(root->next[key[depth]], key, depth + 1);
        if(!temp) root->next.erase(key[depth]);
        else root->next[key[depth]] = temp;

        if (root->next.empty() && !root->eow) {
            delete (root);
            root = NULL;
        }
        return root;
    }

    void remove(string key) {
        deleteNode(this->root, key);
    }
};

template<typename T> trie<T> :: begin()
{

}

template<typename T> trie<T>::end()
{
   
}