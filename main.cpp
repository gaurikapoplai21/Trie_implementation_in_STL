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

    TrieNode<string> root;
    root.key = 'a';
    root.next[root.key] = new TrieNode<string>();
    root.next[root.key]->key='b';
    root.next[root.key]->addParent(&root);
    cout<<root.key<<"\n";
    cout<<root.next[root.key]->key<<"\n";
    TrieNode<string> *temp = root.next[root.key];
    cout<<temp->getParent()->key<<"\n";

    return 0;
}
