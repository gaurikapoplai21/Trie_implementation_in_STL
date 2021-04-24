#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main() {
    
        //trie<string> t;
        //t["hello"] = "hey";
        //t["helloworld"] = "whoa";
        // t["gaurika"] = "girl";
        // cout << t.size() << endl;
        // cout << t["gaurika"] << endl;
        // cout << t.contains("gaurika") << endl;
        // cout << t["joke"] << endl;
        // cout << t.contains("jok") << endl;
        // t1 = t;
        // t.erase("hello");
        //cout << t.size() << endl;
        // cout << t1.size() << endl;
    

    // TrieNode<string> root;
    // root.key = 'a';
    // root.next[root.key] = new TrieNode<string>();
    // root.next[root.key]->key='b';
    // root.next[root.key]->addParent(&root);
    // cout<<root.key<<"\n";
    // cout<<root.next[root.key]->key<<"\n";
    // TrieNode<string> *temp = root.next[root.key];
    // cout<<temp->getParent()->key<<"\n";
    
    //iterator copy assignement
    //*
    // == !=
     //Trie
     /*Trie<int>::iterator it = t.begin();
     for (it; it != it.end;it++)
     {
         cout<<*it<<" ";
     }*/

     trie<int> t;
     t.insert("hello");
     t.insert("helloworld");
     t.insert("hellz");
     //trie<int> t1; 
     trie<int>::iterator it = t.begin();
     bool x = t.begin() == t.begin();
     cout<< (t.begin()==t.end());
     cout<<*t.begin()<<" "<<t.end();
     //cout<<t.begin()==t.end();
     /*for(it; it!=t.end() ;it++)
     {
         cout<<*it<<" ";
     }*/
    
     //trie<int> :: iterator it = t.end(); 

    return 0;
}
