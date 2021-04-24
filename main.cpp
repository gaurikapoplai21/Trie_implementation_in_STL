#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main() {
    trie<string> t;
    t["hello"] = "hey";
    t["helloworld"] = "whoa"; 
    t["gaurika"] = "girl"; 
    cout << t.size() << endl;
    cout << t["gaurika"] << endl;
    cout << t.contains("gaurika") << endl;
    cout << t["joke"] << endl;
    cout << t.contains("jok") << endl;
    t.erase("hellow");
    cout << t.size() << endl;

    
    return 0;
}