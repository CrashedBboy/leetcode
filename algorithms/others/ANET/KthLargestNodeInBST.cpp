/**

Problem: given a BST, find Kth largest elements

Solution: go DFS with order: left subtree -> node -> right subtree


example:

10
    - L: 15
        - L: 18
        - R: 12
            - L: 13
            - R: 11
    - R: 5
        - L: 8
            - L: 9
            - R: 7
        - R: 2

Time Complexity: O(K + h), where h is height of the tree => O (K + logN)

*/

#include <iostream>

using namespace std;

class Node {
public:
    Node* left;
    Node* right;
    int data;
    Node(int d): data(d), left(nullptr), right(nullptr) {}
};

class BST {
public:
    Node* root;
    BST(int d) {
        this->root = new Node(d);
    }
    void insert(int d) {
        Node* t = root;
        while (1) {
            if (d < t->data) {
                if (t->left) {
                    t = t->left;
                }
                else {
                    t->left = new Node(d);
                    break;
                }
            }
            else {
                if (t->right) {
                    t = t->right;
                }
                else {
                    t->right = new Node(d);
                    break;
                }
            }
        }
    }
};

Node* findKthLargest(Node* root, int K);

int main (void) {

    BST tree (10);
    tree.insert(15);
    tree.insert(18);
    tree.insert(12);
    tree.insert(13);
    tree.insert(11);
    tree.insert(5);
    tree.insert(8);
    tree.insert(9);
    tree.insert(7);
    tree.insert(2);

    for (int K = 0; K < 11; K++) {
        Node* kSan = findKthLargest(tree.root, K+1);
        cout << kSan->data << endl;
    }

    return 0;
}


void search(Node* root, int K, int& visitedN, Node*& res) {
    if (!root) {
        return;
    }

    search(root->right, K, visitedN, res);
    if (visitedN < K) {
        visitedN += 1;
        if (visitedN == K) {
            res = root;
        }
        else {
            search(root->left, K, visitedN, res);
        }
    }
}

Node* findKthLargest(Node* root, int K) {

    Node* res = nullptr;
    int visitedN = 0;
    search(root, K, visitedN, res);
    return res;
}