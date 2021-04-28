# Trie_implementation_in_STL
GP Project

## Trie:
Trie is a "Tree" data structure designed primarily to keep track of the prefix of a string, it is used to efficiently insert, delete, find, search strings using prefixes.
In a trie each node has a key character which represents it's contribution to a string, along with that each node has other children keys which divides its path to different strings. The strings stored in a trie is sorted lexographically.

Time complexity: O(M) --> Inserting, Deleting, Searching for a string key.
where M is the length of string key.

## Our Implementation:
An STL compatible "Trie" implementation which can be used as a regular *Trie* as well as a *TrieMap*. 
TrieMap is a templated trie in which each end of word can contain a value associated with it. 
Type of this value is templated meaning it can take data with any datatype. TrieMap works similar to any STL map but internally in a map the keys are stored in a red-black tree whereas in a triemap keys are stored in trie fashion. 

<p align="center">
    <span> Trie Representation </span>
    <img src="https://user-images.githubusercontent.com/44120464/116353671-0e3ca100-a7ac-11eb-9275-45a5fda368e3.png" />
</p>

- <h4>Operations:</h4>
  
  - **Declaration**  : Declare the trie by specifying the keyword "trie" and the datatype.
    - Example: trie\<int> t;
  
  - **Map Insertion** : This is a feature used in triemap for a value lookup associated with a key (end of word).
    - Example: t["hello"] = 10;
    - Time complexity: O(m)
  
  - **Insertion** : Users can also use a public function "insert(<key>)". Using this function user can insert a key in the trie but the value assciated with the key will be a                       default of the selected datatype like the rest of the prefix of that string.
    - Example: t.insert("hello"); 
    - Time complexity: O(m)
  
  - **Deletion** : This is feature to detele a key from the trie using a public function "erase(<key>)". 
    - Example: t.erase("hello"); 
    - Time complexity: O(m)
  
  - **Find** : This is a feature is to find any given key in the trie.
    - *search(\<key>)* : provide a key and an iterator is return pointing to the end of word of that key if the key is found. If not found then iterator pointing to end of the                            trie is returned.
    - *prefix_search(\<key>)* : provide a key and a boolean value is returned, "true" if present, else "false". 
    - *autocomplete(\<key>)* : provide a key and a vector of strings is returned containing all the end of words that can be reached from that prefix.

## How to use:
It is important to make sure all the files trie.hpp, trienode.hpp, trie_iterator.hpp are present in where you are running the code. Then you can use #include "trie.hpp" to use all the functionalities of trie.

**Constructor trie\<T>()**:
```cpp
#include "trie.hpp"
using namespace std;

int main() {
	trie<int> t; // to call the constructor of the trie class
}
```

**Insertion**:
```cpp
#include "trie.hpp"
using namespace std;

int main() {
	trie<int> t; // to call the constructor of the trie class
    t["hello"] = 10; // to call operator[]() function
	// alternatively
	t.insert("helloworld",10); /* note that value component is not compulsory 
    if not provided it takes default value of the template type.*/
}
```

**Deletion**:
```cpp
#include "trie.hpp"
using namespace std;

int main() {
	trie<int> t; // to call the constructor of the trie class
    t["hello"] = 10;
	t.erase("hello") // this is remove the key provided.
}
```
