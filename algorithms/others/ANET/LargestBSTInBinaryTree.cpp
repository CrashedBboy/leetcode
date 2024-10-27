/**

Problem: Given a binary tree, find the largest subtree that is a valid BST in terms of the number of nodes.
Solution:

Traverse the tree, and for each subtree, 
check if it’s a BST by ensuring that all values in the left subtree are less than the root and all values in the right subtree are greater.
Use a helper function that returns information about each subtree (min, max, isBST, size).
For each subtree, track the size of the largest BST found so far.

example:

10
    - L: 7 (**)
        - L: 4
            - L: 2
            - R: 6
        - R: 9
    - R: 8
        - R: 12

The largest BST is the one rooted from 7.
 */


#include <iostream>

using namespace std;

struct Node {
    Node* right;
    Node* left;
    int data;

    Node (int d): data(d), right(nullptr), left(nullptr) {
        cout << "New node: " << this->data << endl;
    }
};

Node* findLargestBST(Node* root);

int main (void) {

    Node* root = new Node(10);
    Node* n1 = new Node(7); root->left = n1;
    Node* n2 = new Node(8); root->right = n2;
    Node* n3 = new Node(4); n1->left = n3;
    Node* n4 = new Node(9); n1->right = n4;
    Node* n5 = new Node(12); n2->right = n5;
    Node* n6 = new Node(2); n3->left = n6;
    Node* n7 = new Node(6); n3->right = n7;

    Node* ans = findLargestBST(root);
    if (ans != nullptr) {
        cout << "Largest BST Root value: " << ans->data << endl;
    }
    return 0;
}

class Info {
    public:
        int min;
        int max;
        unsigned int size;
        bool isNowBST;
        Node* bstRoot;
        Info(): bstRoot(nullptr), size(0), isNowBST(true) {}
        Info(Node* n) {
            this->bstRoot = n;
            this->isNowBST = true;
            if (n != nullptr) {
                this->min = n->data;
                this->max = n->data;
                this->size = 1;
            }
            else {
                this->size = 0;
            }
        }
};

Info _dfs(Node* root) {

    if (root == nullptr) {
        return Info(root);
    }

    Info li = _dfs(root->left);
    Info ri = _dfs(root->right);

    // check: if current subtree a valid BST
    if (li.isNowBST && ri.isNowBST) {
        bool validBST = true;
        if ((li.size > 0 && li.max >= root->data) || (ri.size > 0 && ri.min < root->data)) {
            validBST = false;
        }
        if (validBST) {
            Info i = Info();
            i.bstRoot = root;
            i.max = ri.size? ri.max : root->data;
            i.min = li.size? li.min : root->data;
            i.size = li.size + ri.size + 1;
            i.isNowBST = true;
            return i;
        }
    } 

    if (ri.size >= li.size) {
        ri.isNowBST = false;
        return ri;
    }
    else {
        li.isNowBST = false;
        return li;
    }
}

Node* findLargestBST(Node* root) {
    Info i = _dfs(root);
    return i.bstRoot;
}