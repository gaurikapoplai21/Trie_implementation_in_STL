#ifndef TRIE_H
#define TRIE_H
#include "trienode.hpp"
#include "trie_iterator.hpp"
using namespace std;

template <typename T>
class trie
{
private:
    // Private Members
    TrieNode<T> *root;
    TrieNode<T> *end_;

    // Private Methods
    TrieNode<T> *createNode(char key);
    TrieNode<T> *deleteNode(TrieNode<T> *root, string key, int depth = 0);
    void recursive_destroy(TrieNode<T> *root);
    void deepcopyroot(TrieNode<T> *a, TrieNode<T> *b);
    int checksize(TrieNode<T> *root);
    void updateEnd(bool rem);

public:
     using iterator = trie_iterator<T>;
     using reverse_iterator = std::reverse_iterator<iterator>;

     // begin and end objects of template class trie_iterator
     iterator begin();
     iterator end();
     reverse_iterator rbegin();
     reverse_iterator rend();

     iterator search(std::string);
     iterator prefix_search(std::string);

     trie()
     {
         root = this->createNode('#');
         end_ = this->createNode(char());
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
    updateEnd(1);
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
    updateEnd(0);
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

template <typename T>
void trie<T>::updateEnd(bool rem) {
    TrieNode<T> *parse = this->root;
    while(parse->next.find(char()) == parse->next.end() and !parse->next.empty()) {
        parse = (*(parse->next.rbegin())).second;
    }
    if(rem) {
        parse->next.clear();
        this->end_->parent = nullptr;
    }
    else {
        parse->next[char()] = this->end_;
        this->end_->parent = parse;
    }
}

template<typename T> typename trie<T> :: iterator trie<T> :: begin()
{
    TrieNode<T>* ptr = this->root;
    while(ptr->eow != true)
    {
        ptr = ptr->next.begin()->second;
    }
    iterator it(ptr);
    return it;
}

template <typename T>
typename trie<T>::iterator trie<T>::end()
{
    iterator it2(this->end_);
    return it2;
}

/*template <typename T>
typename trie<T>::reverse_iterator trie<T>::rbegin()
{    
    
    TrieNode<T>* t = this->end().ptr_t;
    --t;
    cout<<t->key;
    iterator k(t);
    reverse_iterator res = k;
    return res;
}*/

/*template <typename T>
typename trie<T>::reverse_iterator trie<T>::rend()
{   
    iterator it(this->root);
    reverse_iterator res(it);//reverse_iterator(it);
    return res;
// return trie<T>::reverse_iterator(trie<T>::begin());
}*/

template <typename T>
typename trie<T>::iterator trie<T>::search(std::string key)
{
TrieNode<T>* t = this->root;
for(int i=0;i<key.size();i++)
{
    if (t->next.find(key[i]) == t->next.end())
    {
        return this->end();
    }
    t = t->next[key[i]];
}
if (t != NULL && t->eow)
{   
    iterator it(t);
    return it;
}
return this->end();
}

template <typename T>
typename trie<T>::iterator trie<T>::prefix_search(std::string key)
{
    TrieNode<T> *t = this->root;
    for (int i = 0; i < key.size(); i++)
    {
        if (t->next.find(key[i]) == t->next.end())
        {
            return this->end();
        }
        t = t->next[key[i]];
    }
    if (t != NULL)
    {
        iterator it(t);
        return it;
    }
    return this->end();
}

#endif