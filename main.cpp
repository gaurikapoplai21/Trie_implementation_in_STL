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
    t.insert("helluz");
    t.insert("helloworld");
    t.insert("helluza");
    t.insert("helluzb");
    t.insert("helluzc");
    trie<int> :: iterator it = t.begin();
    trie<int> :: iterator it1 = t.end();
    // trie<int> :: reverse_iterator it2 = t.rend();
    cout << "h-> " << *it << endl;
    ++it;
    cout << "h-> " << *it << endl;
    ++it;
    cout << "h-> " << *it << endl;
    --it1;
    --it1;
    --it1;
    trie<int>::iterator it2 = t.prefix_search("abc");
    cout << (it2 == t.end()) << endl;

    //  --it;
    //  cout << *it << endl;

    //  int i = 0;
    //  for(;i<=3 and it != t.end(); ++it, i++) {
    //      cout << *it << endl;
    //  }
    //  cout << "---------------" << endl;
    //  for(;it != t.begin(); --it) {
    //      cout << *it << endl;
    //  }
    //  cout << *it << endl;
    // auto it2 = find(t.begin(), t.end(), "helluza");
    // cout << *it2 << endl;

    
    //  for(auto i: t) {
    //      cout << i << endl;
    //  }
    //  cout << *it << endl;
    //  trie<int>::iterator it = t.search("hello");
    //  if(it != t.end())
    //  {
    //      cout<<*it;
    //  }
    //  else
    //  {
    //      cout<<"not found";
    //  }
    //  trie<int>::iterator it2 = t.prefix_search("hello");
    //  if (it2 != t.end())
    //  {
    //      cout << *it2;
    //  }
    //  else
    //  {
    //      cout << "not found";
    //  }
    //trie<int> t1; 
    /*trie<int>::iterator it = t.begin();
    bool x = t.begin() == t.begin();
    cout<< (t.begin()==t.end());
    cout<<*t.begin()<<" "<<t.end();*/

    // trie<int>::iterator it = t.rbegin();
    //cout<<*it<<" ";

    //trie<int>::reverse_iterator it2 = t.rend();
    //cout<<*it2;

    
    /*for(it; it!=t.end() ;it++)
     {
         cout<<*it<<" ";
     }*/

    //trie<int> :: iterator it = t.end(); 

    return 0;
}
