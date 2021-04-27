#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main() {
    trie<string> t, t1;
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
    t1 = t;
    t1.erase("abc");
    t1.insert("abd");
    //trie<string> :: iterator it = t.begin();
    vector<string> v = t.autocomplete("hell");
    vector<string> x = t.autocomplete("z");

    for(auto i: x)
    {
        cout<<i<<" ";
    }

   /* for(auto a : t) {
        cout << a << " ";
    }
    cout << endl;

    for(auto a : t1) {
        cout << a << " ";
    }
    cout << endl;

    it = t.end();
    for(;it!=t.begin();--it) {
        cout << *it << " ";
    }
    cout <<*it<< endl;

    cout << (find(t.begin(), t.end(), "helluzb") != t.end()) << endl;

    cout <<  equal(t.begin(), t.end(), t1.begin());*/

    return 0;
}
