#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main() {
    //implement
    trie<int> t;
    t["hello"] = 10;
    t["helloworld"] = 11; 
    t["gaurika"] = 12; 
    cout << t["gaurika"] << endl;
    cout << t.find("joke") << endl;
    // t.insertNode("hello");
    // t.insertNode("helloworld");
    // t.insertNode("gaurika");
    // trie<int> :: iterator it = t.begin();
    // trie<int> :: iterator it2 = t.end();
    // for(it; it != it2 ;it++)
    // {
    //     cout<<*it<<" ";
    // }

}