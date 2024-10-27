// similiar to LeetCode question: https://leetcode.com/problems/implement-trie-prefix-tree/
// my previous implementation which use fixed character set(a-z):
// https://github.com/CrashedBboy/leetcode/blob/master/algorithms/leetcode/medium/ImplementTrie.cpp


#include <vector>
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> child;
    bool end;
    char c;
    TrieNode(char cc, bool ee): c(cc), end(ee) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode('_', false);
    }
    void insert(string s);
    bool search(string s);
};

void Trie::insert(string s) {
    if (s.size() == 0) {
        return;
    }
    
    TrieNode* currentNode = this->root;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (currentNode->child.find(c) == currentNode->child.end()) {
            currentNode->child.insert({c, new TrieNode(c, false)});
        }
        if (i == s.size() - 1) {
            currentNode->child[c]->end = true;
        }
        currentNode = currentNode->child[c];
    }
}

bool Trie::search(string s) {
    if (s.empty()) {
        return true;
    }

    TrieNode* currentNode = this->root;
    for (int i = 0; i < s.size(); i++) {
        char c = s[i];
        if (currentNode->child.find(c) == currentNode->child.end()) {
            return false;
        }
        currentNode = currentNode->child[c];
    }
    return currentNode->end;
}

int main(void) {

    Trie tree;

    tree.insert("care");
    tree.insert("cat");
    tree.insert("category");

    cout << tree.search("car") << endl;
    cout << tree.search("cat") << endl;
    cout << tree.search("category") << endl;
    cout << tree.search("categoryyy") << endl;
    
    return 0;
}