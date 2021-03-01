// Source : https://leetcode.com/problems/implement-trie-prefix-tree/
// Author : CrashedBboy
// Date   : 2021-03-01

// Questions
/********************************************************************************** 

Implement a trie with insert, search, and startsWith methods.

Example:

Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");   
trie.search("app");     // returns true

Note:

- You may assume that all inputs are consist of lowercase letters a-z.
- All inputs are guaranteed to be non-empty strings.

**********************************************************************************/

// [idea]
// every node in Trie structure has 26 children(another Trie): from a to z,
// but not all children is not null
// to indicate a word's ending: create a label to indicate
// order of implement: insert -> startsWith -> search


#include <vector>
#include <string>
#include <iostream>

using namespace std;

class TrieNode {

public:

    vector<TrieNode*> next;
    bool end;

    TrieNode() : end(false), next(vector<TrieNode*>(26, NULL)) { }
};

class Trie {
public:

    /** Initialize your data structure here. */
    Trie() {

        // create empty node as root
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {

        // iterate the string and create TrieNodes
        int charIndex;
        TrieNode* currentNode = root;
        for (int i = 0; i < word.size(); i++) {
            charIndex = word[i] - 'a';

            if (!currentNode->next[charIndex]) {
                currentNode->next[charIndex] = new TrieNode;
            }

            currentNode = currentNode->next[charIndex];

            // in the last iteration: set the TrieNode.end to be true
            if (i == word.size() - 1) {
                currentNode->end = true;
            }
        }
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {

        // use DFS to reach the end of query word

        int charIndex;
        TrieNode* currentNode = root;

        for (int i = 0; i < word.size(); i++) {

            charIndex = word[i] - 'a';

            // if search fails in the middle: return false
            if (!currentNode->next[charIndex]) {
                return false;
            }

            currentNode = currentNode->next[charIndex];

            // in the last iteration, if the end node.end is false, return false
            if (i == word.size() - 1 && currentNode->end == false) {
                return false;
            }
        }

        return true;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {


        // similar action proceed in search() but we do not have to check node.end

        int charIndex;
        TrieNode* currentNode = root;

        for (int i = 0; i < prefix.size(); i++) {

            charIndex = prefix[i] - 'a';

            // if search fails in the middle: return false
            if (!currentNode->next[charIndex]) {
                return false;
            }

            currentNode = currentNode->next[charIndex];
        }

        return true;
    }

private:

    TrieNode* root;
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

// code for testing
int main() {

    Trie* myTrie = new Trie();

    myTrie->insert("apple");
    bool res_1 = myTrie.search("apple");
    cout << res_1 << endl;
    bool res_2 = myTrie.search("app");
    cout << res_2 << endl;
    bool res_3 = trie.startsWith("app");
    cout << res_3 << endl;
    trie.insert("app");   
    bool res_4 = trie.search("app");
    cout << res_4 << endl;

    return 0;
}