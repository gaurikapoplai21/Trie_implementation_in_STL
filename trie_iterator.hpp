#ifndef TRIE_ITERATOR_H
#define TRIE_ITERATOR_H
#include "trienode.hpp"

template <typename T>
class trie_iterator
{

private:
    TrieNode<T> *ptr_t;

public:
    using iterator_category = std::bidirectional_iterator_tag;
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = value_type *;
    using reference = value_type &;

    //default ctor
    trie_iterator();

    //parameterized ctor
    explicit trie_iterator(TrieNode<T> *ptr);
    
    //copy ctor
    trie_iterator<T>(const trie_iterator<T> &);

    //copy assignment operator
    trie_iterator<T>& operator=(const trie_iterator<T> &);

    //dtor
    ~trie_iterator() = default;

    //operator functions
    trie_iterator<T> operator++(int);  
    trie_iterator<T> &operator++();
    trie_iterator<T> operator--(int);        
    trie_iterator<T> &operator--();
    string operator*() const;

    char getKey();
    T getValue();
    
    //T operator->() const;   //TBD

    //friend functions
    friend bool operator==(const trie_iterator<T>& one, const trie_iterator<T>& two) {return one.ptr_t == two.ptr_t;}
    
    friend bool operator!=(const trie_iterator<T>& one, const trie_iterator<T>& two) {return !(one == two);}
    
    friend ostream &operator<<(ostream &o, const trie_iterator<T> &rhs) {return o << rhs.ptr_t;}
};

// ctor
template <typename T>
trie_iterator<T>::trie_iterator() : ptr_t(NULL) {}

template <typename T>
trie_iterator<T>::trie_iterator(TrieNode<T> *ptr) : ptr_t(ptr) {}

// copy ctor
template <typename T>
trie_iterator<T>::trie_iterator(const trie_iterator<T>& rhs) : ptr_t(rhs.ptr_t) {}

// copy assignment operator
template <typename T>
trie_iterator<T>& trie_iterator<T>:: operator=(const trie_iterator<T> & rhs) {this->ptr_t = rhs.ptr_t; return *this;}

template<typename T>
string trie_iterator<T>::operator*() const 
{
    string str;
    if(!this->ptr_t->eow) return str;
    TrieNode<T>* p = this->ptr_t;
    while (p->getParent() and p->getParent()->getParent())
    {
        str += p->key;
        p = p->getParent(); 
    }
    reverse(str.begin(),str.end());
    return str;
}

template<typename T>
trie_iterator<T> &trie_iterator<T>::operator++() {
    
    if(!this->ptr_t->getParent()) return *this;

    if(this->ptr_t->next.empty()) {
        auto parse = this->ptr_t;
        char temp = parse->key;
        parse = parse->getParent();
        while(parse->getParent()) {
            auto it = parse->next.find(temp); ++it;
            if(it != parse->next.end()) {parse = it->second; break;}
            temp = parse->key;
            parse = parse->getParent();
        }

        this->ptr_t = parse;
        if(!parse->getParent()) return *this;

        if(parse->eow) {
            return *this;
        } 
    }

    do {
        this->ptr_t = (*(this->ptr_t->next.begin())).second;
    } while(!this->ptr_t->eow);

    return *this;
}

template<typename T>
trie_iterator<T> &trie_iterator<T>::operator--() {
    
    auto parse = this->ptr_t;
    if(parse->getParent()) {
        char temp = parse->key;
        parse = parse->getParent();
        while(parse) {
            auto it = parse->next.find(temp);
            if(it != parse->next.begin()) {--it; parse = it->second; break;}
            if(parse->eow) {
                this->ptr_t = parse;
                return *this;
            }
            temp = parse->key;
            parse = parse->getParent();
        }
    }
    
    if(!parse) {return *this;}

    this->ptr_t = parse;

    while(!this->ptr_t->next.empty()) {
        this->ptr_t = (*(this->ptr_t->next.rbegin())).second;
    }

    return *this;
}

template <typename T>
trie_iterator<T> trie_iterator<T>::operator++(int)
{
    trie_iterator<T> temp(*this);
    ++(*this);
    return temp;
}

template <typename T>
trie_iterator<T> trie_iterator<T>::operator--(int)
{
    trie_iterator<T> temp(*this);
    --(*this);
    return temp;
}

template <typename T>
char trie_iterator<T>::getKey()
{
    return this->ptr_t->getKey();
}

template <typename T>
T trie_iterator<T>::getValue()
{
    return this->ptr_t->value;
}

#endif
