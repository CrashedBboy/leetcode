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

// lowest common ancestor
Node* findLCA(Node* root, int val1, int val2) {
    if (!root) return nullptr;

    if (root->data == val1 || root->data == val2) {
        return root;
    }

    Node* left = findLCA(root->left, val1, val2);
    Node* right = findLCA(root->right, val1, val2);

    if (left && right) {
        return root;
    }

    return (left? left : right);
}

int getDistanceFromRoot(Node* root, int target) {

    if (!root) {
        return -1;
    }

    if (root->data == target) {
        return 0;
    }

    int d = getDistanceFromRoot(root->right, target);
    if (d == -1) {
        d = getDistanceFromRoot(root->left, target);
    }
    return (d == -1? -1 : d+1);
}

int getNodeDistance(Node* root, int val1, int val2) {
    Node* LCARoot = findLCA(root, val1, val2);
    if (LCARoot) {
        cout << "LCA" << LCARoot->data << endl;
    }
    return getDistanceFromRoot(LCARoot, val1) + getDistanceFromRoot(LCARoot, val2);
}


// in this testcase we use BST as a binary tree
// but the solution will not assume it is a BST
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

    int distance = getNodeDistance(tree.root, 7, 13); // should be 6
    cout << "Node Distance:" << distance << endl;

    return 0;
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