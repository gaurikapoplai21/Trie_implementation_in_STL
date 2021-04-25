#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main() {
    trie<int> t;
    t.insert("hello");
    t.insert("hell");
    t.insert("helluz");
    t.insert("helloworld");
    t.insert("helluza");
    t.insert("helluzb");
    t.insert("helluzc");
    trie<int> :: iterator it = t.begin();
    trie<int> :: iterator it1 = t.end();

    for(;it != t.end(); ++it) {
        cout << *it << endl;
    }

    for(auto a: t) cout << a << " ";
    cout << endl;

    cout << (find(t.begin(), t.end(), "helluz") != t.end()) << endl;

    // cout << it->value << endl;
    // cout << it->key << endl;
    return 0;
}
