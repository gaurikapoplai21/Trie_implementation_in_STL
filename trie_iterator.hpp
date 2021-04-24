#ifndef TRIE_ITERATOR_H
#define TRIE_ITERATOR_H
#include "trienode.hpp"

template <typename T>
class trie_iterator
{
private:
    TrieNode<T> *ptr_t;

public:
    trie_iterator();                          //default ctor
    explicit trie_iterator(TrieNode<T> *ptr); //parameterized ctor
    
    //copy ctor
    trie_iterator<T>(const trie_iterator<T> &);

    //copy assignment operator
    trie_iterator<T> operator=(const trie_iterator<T> &);

    //dtor
    ~trie_iterator() = default;

    //operator functions
    trie_iterator<T> operator++(int) = delete;        //post
    trie_iterator<T> *operator++() = delete; //tbd pre
    trie_iterator<T> operator--(int);        //post
    trie_iterator<T> operator--() = delete;  //tbd pre
    T operator*() const;
    //T operator->() const;

    //friend functions
    friend bool operator==(const trie_iterator<T> &, const trie_iterator<T> &);
    friend bool operator!=(const trie_iterator<T> &, const trie_iterator<T> &);
    friend bool operator>=(const trie_iterator<T> &, const trie_iterator<T> &);
    friend bool operator<=(const trie_iterator<T> &, const trie_iterator<T> &);
    friend bool operator<(const trie_iterator<T> &, const trie_iterator<T> &);
    friend bool operator>(const trie_iterator<T> &, const trie_iterator<T> &);
};

template <typename T>
trie_iterator<T>::trie_iterator() : ptr_t(NULL)
{
}

template <typename T>
trie_iterator<T>::trie_iterator(TrieNode<T> *ptr) : ptr_t(ptr)
{

}

//copy assignment operator
template <typename T>
trie_iterator<T> trie_iterator<T>:: operator=(const trie_iterator<T> & rhs) 
{
    this->ptr_t = rhs->ptr_t;

}

//copy ctor
template <typename T>
trie_iterator<T>::trie_iterator(const trie_iterator<T>& rhs) : ptr_t(rhs.ptr_t){ }


/*template <typename T>
trie_iterator<T>::bool operator==(const trie_iterator<T> &, const trie_iterator<T> &)
{
}

template <typename T>
trie_iterator<T>::bool operator!=(const trie_iterator<T> &one, const trie_iterator<T> &two)
{
    return !(one == two);
}*/

#endif
