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
    void recursiveDestroy(TrieNode<T> *root);
    void deepCopyRoot(TrieNode<T> *a, TrieNode<T> *b);
    int checkSize(TrieNode<T> *root);
    void dfs(TrieNode<T> *, vector<string> &, string);

public:
    using iterator = trie_iterator<T>;
    using reverse_iterator = std::reverse_iterator<iterator>;

    // begin and end objects of template class trie_iterator
    iterator begin();
    iterator end();
    reverse_iterator rbegin();
    reverse_iterator rend();

    iterator search(std::string);
    bool prefix_search(std::string);
    vector<string> autocomplete(std::string);

    int getHeight(TrieNode<T> *temp)
    {
        if (temp->next.empty())
            return 0;
        int m = 0;
        for (auto a : temp->next)
        {
            m = max(m, 1 + getHeight(a.second));
        }
        return m;
    }

    void printFill(vector<vector<char>> &tree, TrieNode<T> *temp, int l, int r, int depth)
    {
        tree[depth + 1][(l + r) / 2] = temp->key;
        if (temp->next.empty())
        {
            tree[depth][(l + r) / 2] = '|';
            return;
        }

        int interval = (r - l) / temp->next.size(), start = l;
        for (auto a : temp->next)
        {
            tree[depth][(l + r) / 2] = '|';
            printFill(tree, a.second, start, start + interval, depth + 2);
            start += interval;
        }
    }

    void printTree()
    {
        TrieNode<T> *temp = this->root;
        int h = getHeight(temp), w = 50;
        vector<vector<char>> tree(2 * (h + 1), vector<char>(w, ' '));
        printFill(tree, temp, 0, w, 0);
        for (int i = 0; i < tree.size(); i++)
        {
            int in = -1, out = -1;
            for (int j = 0; j < tree[i].size(); j++)
            {
                if (tree[i][j] == '|' and i - 1 >= 0 and tree[i - 1][j] == ' ')
                {
                    if (in == -1)
                        in = j;
                    else
                        out = j;
                }
            }
            for (int j = 0; j < tree[i].size(); j++)
            {
                int k = in;

                while (k != -1 and k <= out)
                {
                    tree[i][k] = '_';
                    k++;
                }
                cout << tree[i][j];
            }
            cout << endl;
        }
    }

    trie()
    {
        root = this->createNode('#');
        end_ = this->createNode(char());
        end_->next['#'] = root;
        root->parent = end_;
    }

    ~trie()
    {
        TrieNode<T> *parse = this->root;
        if(root != nullptr)
            recursiveDestroy(root);
    }

    T &operator[](string key)
    {
        return ((this->insert(key))->value);
    }

    trie<T> &operator=(const trie<T> &x)
    {
        if (this != &x)
        {
            recursiveDestroy(this->end_);
            this->root = this->createNode('#');
            this->end_ = this->createNode(char());
            this->end_->next['#'] = this->root;
            this->root->parent = this->end_;
            deepCopyRoot(x.root, this->root);
        }
        return *this;
    }

    trie(const trie<T> &x)
    {
        if (this != &x)
        {
            this->root = this->createNode('#');
            end_ = this->createNode(char());
            end_->next['#'] = root;
            root->parent = end_;
            deepCopyRoot(x.root, this->root);
        }
    }

    trie(trie<T>&& rhs)
    :root(rhs.root),end_(rhs.end_)
    {
        rhs.root = nullptr;
        rhs.end_ = nullptr;
    }

    trie& operator=(trie<T>&& rhs) {
        if(this != &rhs) {
            if(this->root != nullptr) {
                recursiveDestroy(this->root);
            }
            this->root = rhs.root;
            this->end_ = rhs.end_;
            rhs.root = nullptr;
            rhs.end_ = nullptr;
        }
        return *this;
    }

    TrieNode<T> *insert(string key, T value = T());
    bool contains(string key);
    void erase(string key);
    bool empty();
    int size();
};

template <typename T>
void trie<T>::deepCopyRoot(TrieNode<T> *a, TrieNode<T> *b)
{
    b->eow = a->eow;
    b->key = a->key;
    b->value = a->value;
    for (auto x : a->next)
    {
        b->next[x.first] = createNode(x.first);
        b->next[x.first]->addParent(b);
        deepCopyRoot(x.second, b->next[x.first]);
    }
}

template <typename T>
void trie<T>::recursiveDestroy(TrieNode<T> *root)
{

    //if(!root) return;

    if (root->next.empty())
    {
        delete (root);
        root = nullptr;
        return;
    }

    auto it = root->next.cbegin();
    while (it != root->next.cend())
    {
        if (root->next.find(it->first) != root->next.cend())
        {
            recursiveDestroy(it->second);
            it = root->next.erase(it);
        }
        else
            ++it;
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
    // node->fullkey = string();
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
    // parse->fullkey = key;
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
int trie<T>::checkSize(TrieNode<T> *root)
{
    int t = 0;
    if (!root)
        return 0;
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
    return checkSize(root);
}

template <typename T>
typename trie<T>::iterator trie<T>::begin()
{
    if (this->empty())
        return this->end();
    TrieNode<T> *ptr = this->root;
    while (ptr->eow != true)
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
    // cout<<t->key;
    iterator k(t);
    reverse_iterator res = k;
    return res;
    // return make_reverse_iterator(end());
}

template <typename T>
typename trie<T>::reverse_iterator trie<T>::rend()
{   
    iterator it(this->end_);
    reverse_iterator res(it);//reverse_iterator(it);
    return res;
    // return make_reverse_iterator(begin());
}*/

template <typename T>
typename trie<T>::iterator trie<T>::search(std::string key)
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
    if (t != NULL && t->eow)
    {
        iterator it(t);
        return it;
    }
    return this->end();
}

template <typename T>
bool trie<T>::prefix_search(std::string key)
{
    TrieNode<T> *t = this->root;
    for (int i = 0; i < key.size(); i++)
    {
        if (t->next.find(key[i]) == t->next.end())
        {
            return false;
        }
        t = t->next[key[i]];
    }
    if (t != NULL)
    {
        return true;
    }
    return false;
}

template <typename T>
void trie<T>::dfs(TrieNode<T> *ptr, vector<string> &v, string prefix)
{
    if (ptr->eow)
    {
        v.push_back(prefix);
    }
    if (ptr->next.empty())
    {
        return;
    }

    for (auto it : ptr->next)
    {
        prefix += (it.first);
        dfs(ptr->next[(it.first)], v, prefix);
        prefix.pop_back();
    }
}

template <typename T>
vector<string> trie<T>::autocomplete(std::string key)
{
    vector<string> v;
    TrieNode<T> *t = this->root;
    for (int i = 0; i < key.size(); i++)
    {
        if (t->next.find(key[i]) == t->next.end())
        {
            return v;
        }
        t = t->next[key[i]];
    }
    if (t == NULL)
    {
        return v;
    }

    dfs(t, v, key);
    return v;
}

template <typename T>
void myswap(trie<T>& lhs, trie<T>& rhs)
{
        trie<T> temp(move(lhs)); //move ctor
        lhs = move(rhs); // move assignment op
        rhs = move(temp);

}

#endif