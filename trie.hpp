#include <bits/stdc++.h>
#include "trienode.hpp"
#include "trie_iterator.hpp"
using namespace std;

template <typename T>
class trie
{
private:
    // Private Members
    TrieNode<T> *root;

    // Private Methods
    TrieNode<T> *createNode(char key);
    TrieNode<T> *deleteNode(TrieNode<T> *root, string key, int depth = 0);
    void recursive_destroy(TrieNode<T> *root);
    void deepcopyroot(TrieNode<T> *a, TrieNode<T> *b);
    int checksize(TrieNode<T> *root);

public:
     using iterator = trie_iterator<T>;

    // begin and end objects of template class trie_iterator
     iterator begin();
     iterator end();

    trie()
    {
        root = this->createNode('#');
    }

    ~trie()
    {
        TrieNode<T> *parse = this->root;
        recursive_destroy(root);
    }

    T &operator[](string key)
    {
        return ((this->insert(key))->value);
    }

    trie<T> &operator=(const trie<T> &x)
    {
        if (this != &x)
        {
            recursive_destroy(this->root);
            this->root = this->createNode('#');
            deepcopyroot(x.root, this->root);
        }
        return *this;
    }

    trie (const trie<T> &x)
    {
        if (this != &x)
        {
            this->root = this->createNode('#');
            deepcopyroot(x.root, this->root);
        }
    }

    TrieNode<T> *insert(string key, T value = T());
    bool contains(string key);
    void erase(string key);
    bool empty();
    int size();
};

template <typename T>
void trie<T>::recursive_destroy(TrieNode<T> *root)
{
    if (root->next.empty())
    {
        delete (root);
        root = nullptr;
        return;
    }
    
    auto it = root->next.cbegin();
    while (it != root->next.cend())
    {
        if(root->next.find(it->first) != root->next.cend()) {
            recursive_destroy(it->second);
            it = root->next.erase(it);
        } else ++it;
    }

    if (root->next.empty())
    {
        delete (root);
        root = nullptr;
    }
}

template <typename T>
TrieNode<T> *trie<T>::createNode(char key)
{
    TrieNode<T> *node = new TrieNode<T>();
    node->key = key;
    node->eow = 0;
    node->value = T();
    return node;
}

template <typename T>
TrieNode<T> *trie<T>::insert(string key, T value)
{
    TrieNode<T> *parse = this->root;
    for (int i = 0; i < key.size(); i++)
    {
        if (parse->next.find(key[i]) == parse->next.end())
        {
            parse->next[key[i]] = this->createNode(key[i]);
            parse->next[key[i]]->addParent(parse);
        }
        parse = parse->next[key[i]];
    }
    parse->eow = 1;
    return parse;
}

template <typename T>
TrieNode<T> *trie<T>::deleteNode(TrieNode<T> *root, string key, int depth)
{
    if (!root)
        return NULL;
    if (depth == key.size())
    {
        if (root->eow)
            root->eow = 0;
        if (root->next.empty())
        {
            delete (root);
            root = NULL;
        }
        return root;
    }

    TrieNode<T> *temp = this->deleteNode(root->next[key[depth]], key, depth + 1);
    if (!temp)
        root->next.erase(key[depth]);
    else
        root->next[key[depth]] = temp;

    if (root->next.empty() && !root->eow)
    {
        delete (root);
        root = NULL;
    }
    return root;
}

template <typename T>
bool trie<T>::contains(string key)
{
    TrieNode<T> *parse = this->root;
    for (int i = 0; i < key.size(); i++)
    {
        if (parse->next.find(key[i]) == parse->next.end())
            return 0;
        parse = parse->next[key[i]];
    }
    return parse->eow;
}

template <typename T>
void trie<T>::erase(string key)
{
    deleteNode(this->root, key);
}

template <typename T>
bool trie<T>::empty()
{
    return this->root->next.empty();
}

template <typename T>
int trie<T>::checksize(TrieNode<T> *root)
{
    int t = 0;
    if (!root) return 0;
    if (root->eow)
        t = 1;
    for (auto a : root->next)
    {
        t += checksize(a.second);
    }
    return t;
}

template <typename T>
int trie<T>::size()
{
    return checksize(root);
}

/*template <typename T>
typename trie<T>::iterator trie<T>::begin()
{
    trie_iterator<T> it = *(new trie_iterator<T>(this->root));
    return ++it;
}*/

 template<typename T> typename trie<T> :: iterator trie<T> :: begin()
 {
     
     TrieNode<T>* ptr = this->root;
     while(ptr->eow != true)
     {
         ptr = ptr->next.begin()->second;
     }
     cout<<ptr->key;
     iterator it(ptr);
     return it;
 }

 /*template<typename T> iterator trie<T>::end()
 {

 }*/
