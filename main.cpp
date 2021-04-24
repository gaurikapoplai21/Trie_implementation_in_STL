#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main() {
    trie<string> t;
    t["hello"] = "hey";
    t["helloworld"] = "whoa"; 
    t["gaurika"] = "girl"; 
    cout << t["gaurika"] << endl;
    cout << t.find("joke") << endl;
    return 0;
}