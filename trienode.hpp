#include <bits/stdc++.h>
using namespace std;
#define SIZE 26

struct TrieNode{
    map<char, struct TrieNode *> next;
    int value;
    bool eow;
};

typedef struct TrieNode TrieNode;