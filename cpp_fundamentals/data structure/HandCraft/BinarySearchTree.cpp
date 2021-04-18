#include <iostream>
#include <stack>

using namespace std;


class BinaryTreeNode {

public:

    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x, BinaryTreeNode* left, BinaryTreeNode* right) : val(x), left(left), right(right) { }
    BinaryTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode() : val(0), left(nullptr), right(nullptr) {}

private:

};

class BinarySearchTree {

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(int x) {
        BinaryTreeNode* newNode = new BinaryTreeNode(x);

        if (root == nullptr) {
            root = newNode;
            return;
        }
        else {

            BinaryTreeNode* current = root;
            while (true) {

                if (x >= current->val) {

                    if (current->right == nullptr) {
                        current->right = newNode;
                        return;
                    }
                    else {
                        current = current->right;
                    }
                }
                else if (x < current->val) {

                    if (current->left == nullptr) {
                        current->left = newNode;
                        return;
                    }
                    else {
                        current = current->left;
                    }
                }
            }
        }
    }

    // erase the first found
    void erase(int x) {}

    bool contains(int x) {

        return false;
    }

    void getSortedSequence() {

        if (root == nullptr) { return; }

        stack<BinaryTreeNode*> traversalStack;

        // traversalStack.push(root);

        BinaryTreeNode* current = root;

        while (!traversalStack.empty() || current != nullptr) {

            while (current != nullptr) {
                traversalStack.push(current);
                current = current->left;
            }

            current = traversalStack.top(); traversalStack.pop();

            cout << current->val << ",";

            current = current->right;
        }

        cout << endl;
    }

private:
    BinaryTreeNode* root;
};

int main() {

    BinarySearchTree bst;

    bst.insert(4);
    bst.insert(3);
    bst.insert(2);
    bst.insert(1);

    bst.getSortedSequence();



    return 0;
}