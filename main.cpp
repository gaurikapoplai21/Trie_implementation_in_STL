#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;
#define SIZE 26

int main() {
    // trie t;
    // t.insertNode("nice", 69);
    // cout << "donno" << endl;
    // cout << t.searchNode("nice") << endl;
    // t.deleteNode(t.root, "nice");
    // cout << t.searchNode("nice") << endl;
    trie t;
    t["lol"] = 10;
    cout << ++t["lol"] << endl;
    // cout << t["nice"] << endl;
    cout << t.find("nice") <<endl;
    cout << t.empty() << endl;
    t.remove("lol");
    cout << t.empty() << endl;
    cout << t.find("lol") << endl;
    return 0;
}