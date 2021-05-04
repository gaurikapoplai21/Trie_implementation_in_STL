#include <bits/stdc++.h>
#include "trie.hpp"
using namespace std;

int main()
{
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

    trie<string>::iterator it = t.begin();
    vector<string> v = t.autocomplete("hell");
    vector<string> x = t.autocomplete("z");

    cout << "Auto-complete result \'v\':" << endl;
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;
    cout << endl;

    cout << "Auto-complete result \'x\':" << endl;
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;

    cout << "T1 Forward:" << endl;
    for (auto a : t1)
    {
        cout << a << " ";
    }
    cout << endl;
    cout << endl;

    cout << "T Reverse: " << endl;
    it = t.end();
    for (; it != t.begin(); --it)
    {
        if (it != t.end())
            cout << *it << " ";
    }
    cout << *it << endl;
    cout << endl;

    cout << "STD::Find" << endl;
    cout << (find(t.begin(), t.end(), "helluzb") != t.end()) << endl;
    cout << endl;

    cout << "STD::equal" << endl;
    cout << equal(t.begin(), t.end(), t1.begin()) << endl;
    cout << endl;

    cout << "begin(t):" << endl;
    cout << *begin(t) << endl;
    cout << endl;

    cout << "end(t)-1:" << endl;
    cout << *(--end(t)) << endl;
    cout << endl;

    cout << "begin == end:" << endl;
    vector<int> tx;
    cout << (tx.begin() == tx.end()) << endl;
    cout << endl;

    t.printTree();
    return 0;
}