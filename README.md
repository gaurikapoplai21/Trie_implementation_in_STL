# Trie_implementation_in_STL
GP Project

## Trie:
Trie is a "Tree" data structure designed primarily to keep track of the prefix of a string, it is used to efficiently insert, delete, find, search strings using prefixes.
In a trie each node has a key character which represents it's contribution to a string, along with that each node has other children keys which divides its path to different strings. The strings stored in a trie is sorted lexicographically.

Time complexity: O(M) --> Inserting, Deleting, Searching for a string key.
where M is the length of string key.

## Our Implementation:
An STL compatible "Trie" implementation which can be used as a regular *Trie* as well as a *TrieMap*. <br>
TrieMap is a templated trie in which each end of word can contain a value associated with it. <br>
Type of this value is templated meaning it can take data with any datatype. TrieMap works similar to any STL map but internally in a map the keys are stored in a red-black tree whereas in a triemap keys are stored in trie fashion. 

<p align="center">
    <span> Trie Representation </span><br>
    <img src="https://user-images.githubusercontent.com/44120464/116353671-0e3ca100-a7ac-11eb-9275-45a5fda368e3.png" />
</p>

## How to use:
It is important to make sure all the files trie.hpp, trienode.hpp, trie_iterator.hpp are present in where you are running the code. Then you can use #include "trie.hpp" to use all the functionalities of trie.

```cpp
#include "trie.hpp" // include trie to access all the trie features
using namespace std;

int main() {
  return 0;
}
```

## Operations:
  
- **Declaration**  : Declare the trie by specifying the keyword "trie" and the datatype.
  - Example: trie\<int> t;<br><br>
  ```cpp
  #include "trie.hpp"
  using namespace std;

  int main() {
    trie<int> t; // to call the constructor of the trie class
  }
  ```
  
- **Insertion**:
  - *[] Insertion* : This is a feature used in triemap for a value lookup associated with a key (end of word).
    - Example: t["hello"] = 10;
    - Time complexity: O(m)

  - *Function Insertion* : Users can also use a public function "insert(<key>)". Using this function user can insert a key in the trie but the value assciated with the key will be a default of the selected datatype like the rest of the prefix of that string.
    - Example: t.insert("hello"); 
    - Time complexity: O(m)<br><br>
  ```cpp
  #include "trie.hpp"
  using namespace std;

  int main() {
    trie<int> t;
    t["hello"] = 10; // to call operator[]() function
    // alternatively
    t.insert("helloworld",10); // note that 'value' component is not compulsory 
    //if not provided it takes default value of the template type.
  }
  ```

- **Deletion** : This is feature to delete a key from the trie using a public function "erase(<key>)". 
  - Example: t.erase("hello"); 
  - Time complexity: O(m)<br><br>
  ```cpp
  #include "trie.hpp"
  using namespace std;

  int main() {
    trie<int> t;
    t["hello"] = 10;
    t.erase("hello"); // this is remove the key provided.
  }
  ```

- **Find** : This is a feature is to find any given key in the trie.
  - *contains(\<key>)* : provide a key and an iterator is return pointing to the end of word of that key if the key is found. If not found then iterator pointing to end of the trie is returned.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello")
      bool it = t.search("hello"); // output -> true
      bool it = t.search("hell"); // output -> false
    }
    ```

  - *prefix_search(\<key>)* : provide a key and a boolean value is returned, "true" if present, else "false". 
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello")
      bool a = t.prefix_search("hell"); // output -> true
      bool b = t.prefix_search("helm"); // output -> false
    }
    ```

  - *autocomplete(\<key>)* : provide a key and a vector of strings is returned containing all the end of words that can be reached from that prefix.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello")
      t.insert("helloworld")
      t.insert("hex")
      vector<string> arr = t.autocomplete("hell"); // output -> {"hello", "helloworld"}
    }
    ```

- **Empty** : checks if the trie is empty or not using "empty()". If trie is empty then it contains only root and end. Returns true is empty, else false.
  ```cpp
  #include "trie.hpp"
  using namespace std;

  int main() {
    trie<int> t;
    bool a = t.empty(); // output -> true
    t.insert("hello");
    bool a = t.empty(); // output -> false
  }
  ```

- **Size** : Returns an integer stating the size or total number of keys (end of words) in the trie.
  ```cpp
  #include "trie.hpp"
  using namespace std;

  int main() {
    trie<int> t;
    t.insert("hello");
    int a = t.size(); // output -> 1
  }
  ```

## Iterators trie\<T>::iterators:
Iterators are also supported in our trie implementation and are pointers to a particular node which are marked as end of word and a special end of trie location.<br>
Users are restricted by iterators pointing to only end of words and cannot access any prefix nodes. Modifying trie structure access are strictly restricted.

- **Operations**:
  - **Declaration**: this calls the trie_iterator class constructor to return an iterator object.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int>::iterator it;
    }
    ```

  - **Begin** : this points to the first end of word of the trie.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello");
      trie<int>::iterator it = t.begin(); // points to node 'o'
    }
    ```

  - **End** : this points to the end of the trie.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello");
      trie<int>::iterator it = t.end(); // points to end of trie
    }
    ```

  - **++ Operator** : this increments the pointer and moves its position to the next end of word.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello");
      t.insert("helloworld");
      trie<int>::iterator it = t.begin();
      ++it; // points to node 'd'
    }
    ```

  - **-- Operator** : this decrements the pointer and moves its position to the previous end of word.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello");
      trie<int>::iterator it = t.end(); 
      --it; // points to node 'o'
    }
    ```

  - **Deference** : this calls the "operator*()" which returns a string which is the key ending at that point.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t;
      t.insert("hello");
      trie<int>::iterator it = t.begin(); 
      cout << *it; // output -> "hello"
    }
    ```

  - **find** : 
    - *search(\<key>)* : provide a key and an iterator is return pointing to the end of word of that key if the key is found. If not found then iterator pointing to end of the trie is returned.
      ```cpp
      #include "trie.hpp"
      using namespace std;

      int main() {
        trie<int> t;
        t.insert("hello")
        trie<int>::iterator it = t.search("hello"); // output -> iterator to end of word "hello"
        trie<int>::iterator it = t.search("git"); // output -> iterator to end of trie
      }
      ```

    - *std::find*: provide "begin()" and "end()" of the trie and provide a key to be searched for, if found returns pointer to the key else, end of trie.
      ```cpp
      #include "trie.hpp"
      using namespace std;

      int main() {
        trie<int> t;
        t.insert("hello")
        trie<int>::iterator it = find(t.begin(), t.end(), "hello"); // output -> iterator to end of word "hello"
        trie<int>::iterator it = find(t.begin(), t.end(), "git"); // output -> iterator to end of trie
      }
      ```
    
  - **std::equal** : compares two tries, provide "begin()" and "end()" of the first trie and "begin()" of the second trie. Returns true if equal else false.
    ```cpp
    #include "trie.hpp"
    using namespace std;

    int main() {
      trie<int> t1, t2;
      t1.insert("hello")
      t2.insert("hello")
      bool a = equals(t1.begin(), t1.end(),t2.begin()); // output -> true
    }
    ```