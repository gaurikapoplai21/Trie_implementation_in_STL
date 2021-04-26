#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TrieNode
{

public:
  map<char, TrieNode<T> *> next;
  char key;
  // string fullkey;
  T value;
  bool eow;
  TrieNode<T> *parent;

  void addParent(TrieNode<T> *parent);
  char getKey();
  TrieNode<T> *getParent();

private:
  
};

template <typename T>
void TrieNode<T>::addParent(TrieNode<T> *parent) {this->parent = parent;}

template <typename T>
char TrieNode<T>::getKey() {return this->key;}

template <typename T>
TrieNode<T> *TrieNode<T>::getParent() {return this->parent;}

#endif
