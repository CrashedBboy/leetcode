#include <iostream>
#include <cmath>

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

int getTreeHeight(Node* root) {
    if (root == nullptr) {
        return 0;
    }

    return max(getTreeHeight(root->right), getTreeHeight(root->left)) + 1;
}

int main () {
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

    cout << getTreeHeight(tree.root) << endl;
}

/*
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
*/