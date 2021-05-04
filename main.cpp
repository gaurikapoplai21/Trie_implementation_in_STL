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

#if 0
    trie<string>::iterator it = t.begin();
    vector<string> v = t.autocomplete("hell");
    vector<string> x = t.autocomplete("z");

    cout << "Auto-complete result \'v\':" << endl;
    for (auto i : x)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "Auto-complete result \'x\':" << endl;
    for (auto a : v)
    {
        cout << a << " ";
    }
    cout << endl;

    cout << "T1:" << endl;
    for (auto a : t1)
    {
        cout << a << " ";
    }
    cout << endl;

    cout << "Reverse: " << endl;
    it = t.end();
    for (; it != t.begin(); --it)
    {
        if (it != t.end())
            cout << *it << " ";
    }
    cout << *it << endl;

    cout << "STD::Find" << endl;
    cout << (find(t.begin(), t.end(), "helluzb") != t.end()) << endl;

    cout << "STD::equal" << endl;
    cout << equal(t.begin(), t.end(), t1.begin()) << endl;

    cout << "begin(t):" << endl;
    cout << *begin(t) << endl;

    cout << "end(t)-1:" << endl;
    cout << *(--end(t)) << endl;

    cout << "begin == end:" << endl;
    vector<int> tx;
    cout << (tx.begin() == tx.end()) << endl;
#endif

#if 0
    cout<<"printing t\n";
    for (auto a : t)
    {
        cout << a << " ";
    }cout<<"\n";

    cout<<"printing t2\n";
    trie<string> t2(move(t));
    for (auto a : t2)
    {
        cout << a << " ";
    }cout<<"\n";


#endif

#if 0
    cout<<"printing t\n";
    for (auto a : t)
    {
        cout << a << " ";
    }cout<<"\n";   

    t1 = move(t); // move assign


    cout<<"printing t1\n";
    for (auto a : t1)
    {
        cout << a << " ";
    }cout<<"\n";   

#endif

#if 1
    cout<<"before swap\n";

    cout<<"printing t\n";
    for (auto a : t)
    {
        cout << a << " ";
    }cout<<"\n";  


    cout<<"printing t1\n";
    for (auto a : t1)
    {
        cout << a << " ";
    }cout<<"\n";  

    myswap(t,t1);

    cout<<"after swap\n";

    cout<<"printing t\n";
    for (auto a : t)
    {
        cout << a << " ";
    }cout<<"\n";  


    cout<<"printing t1\n";
    for (auto a : t1)
    {
        cout << a << " ";
    }cout<<"\n";

#endif
    return 0;
}