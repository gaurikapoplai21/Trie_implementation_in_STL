#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main() {
    trie<int> t, t1;
    t.insert("abc");
    t.insert("hello");
    t.insert("hell");
    t.insert("helluz");
    t.insert("helloworld");
    t.insert("helluza");
    t.insert("helluzb");
    t.insert("helluzbg");
    t.insert("helluzc");

    t1.insert("abc");
    t1.insert("hello");
    t1.insert("hell");
    t1.insert("helluz");
    t1.insert("helloworld");
    t1.insert("helluza");
    t1.insert("helluzb");
    t1.insert("helluzbg");
    t1.insert("helluzc");
    trie<int> :: iterator it = t.begin();

    vector<string> a,b;

    for(it = t.begin();it != t.end(); ++it) {
        a.push_back(*it);
    }

    for(it = t.end();it != t.begin(); --it) {
        if(it != t.end()) b.push_back(*it);
    }
    b.push_back(*it);
    reverse(b.begin(), b.end());
    for(auto i : a) {
        cout << i << " ";
    }
    cout << endl;
    for(auto i : b) {
        cout << i << " ";
    }
    cout << endl;

    cout << equal(t.begin(), t.end(), t1.begin());
    
    // for(auto a: t) cout << a << " ";
    // cout << endl;

    // cout << (find(t.begin(), t.end(), "helluz") != t.end()) << endl;

    return 0;
}
