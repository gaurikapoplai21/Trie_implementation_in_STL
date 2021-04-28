# Trie_implementation_in_STL
GP Project

Trie:
Trie is a "Tree" data structure designed primarily to keep track of the prefix of a string, it is used to efficiently insert, delete, find, search strings using prefixes.
In a trie each node has a key character which represents it's contribution to a string, along with that each node has other children keys which divides its path to different strings. The strings stored in a trie is sorted lexographically.

Time complexity: O(M) --> Inserting, Deleting, Searching for a string key.
where M is the length of string key.

Our Implementation:
An STL compatible "Trie" implementation which can be used as a regular *Trie* as well as a *TrieMap*. TrieMap is a templated trie in which each end of word can contain a value associated with it. Type of this value is templated meaning it can take data with any datatype.

![trie](https://user-images.githubusercontent.com/44120464/116353671-0e3ca100-a7ac-11eb-9275-45a5fda368e3.png)

