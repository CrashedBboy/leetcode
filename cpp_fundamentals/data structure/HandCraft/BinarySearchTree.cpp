#include "BinarySearchTree.h"
#include <iostream>

using namespace std;

BinaryTreeNode::BinaryTreeNode(int x, BinaryTreeNode* left, BinaryTreeNode* right): val(x), left(left), right(right) { }
BinaryTreeNode::BinaryTreeNode(int x): val(x), left(nullptr), right(nullptr) { }
BinaryTreeNode::BinaryTreeNode(): val(0), left(nullptr), right(nullptr) {}

BinarySearchTree::BinarySearchTree() : root(nullptr), uniqueKey(false) {
    fakeNull = new BinaryTreeNode(-1);
}

BinarySearchTree::BinarySearchTree(bool unique) : root(nullptr), uniqueKey(unique) {
    fakeNull = new BinaryTreeNode(-1);
}

void BinarySearchTree::insert(int x) {
    BinaryTreeNode* newNode = new BinaryTreeNode(x);

    if (root == nullptr) {
        root = newNode;
        return;
    }
    else {

        BinaryTreeNode* current = root;
        while (true) {

            if (x >= current->val) {

                // duplicated key is not allowed
                if (x == current->val && uniqueKey == true) {
                    return;
                }

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

BinaryTreeNode* BinarySearchTree::minValueNode(BinaryTreeNode* root, BinaryTreeNode* targetParent) {

    BinaryTreeNode* current = root;
    while (current && current->left != nullptr) {
        targetParent = current;
        current = current->left;
    }

    return current;
}

void BinarySearchTree::erase(int x) {

    if (root == nullptr) { return; }

    BinaryTreeNode* targetParent = fakeNull;
    BinaryTreeNode* target = search(x, targetParent);

    cout << "Target val = " << target->val << endl;
    cout << "Target Parent val = " << targetParent->val << endl;

    if (target == nullptr) { return; }

    if (target->left == nullptr && target->right == nullptr) {
        if (targetParent != fakeNull) {
            if (targetParent->left == target) { targetParent->left = nullptr; }
            else { targetParent->right = nullptr; }
        }
        else {
            root = nullptr;
        }

        delete target;
    }
    else if (target->left == nullptr) {
        // target->right is not null
        if (targetParent != fakeNull) {
            if (targetParent->left == target) { targetParent->left = target->right; }
            else { targetParent->right = target->right; }
        }
        else {
            root = target->right;
        }

        delete target;
    }
    else if (target->right == nullptr) {
        // target->left is not null
        if (targetParent != fakeNull) {
            if (targetParent->left == target) { targetParent->left = target->left; }
            else { targetParent->right = target->left; }
        }
        else {
            root = target->left;
        }

        delete target;
    }
    else {
        // both target->left and target->right are not null

        // get successor & its parentss
        BinaryTreeNode* successorParent = target;
        BinaryTreeNode* successor = BinarySearchTree::minValueNode(target->right, successorParent);

        // connect successor's child under successor's parent
        BinaryTreeNode* successorChild;
        if (successor->left != nullptr) {
            successorChild = successor->left;
        }
        else {
            successorChild = successor->right;
        }

        if (successorParent->right == successor) {
            successorParent->right = successorChild;
        }
        else {
            successorParent->left = successorChild;
        }

        // replace the value of target by successor's
        target->val = successor->val;

        // free successor
        delete successor;
    }
}

bool BinarySearchTree::contains(int x) {

    BinaryTreeNode* current = root;

    while (current != nullptr) {

        if (x == current->val) { return true; }
        else if (x > current->val) { current = current->right; }
        else if (x < current->val) { current = current->left; }
    }

    return false;
}

BinaryTreeNode* BinarySearchTree::search(int x, BinaryTreeNode* targetParent) {

    BinaryTreeNode* current = root;

    while (current != nullptr) {
        if (x == current->val) { break; }
        else if (x > current->val) {
            targetParent = current; current = current->right;
        }
        else if (x < current->val) {
            targetParent = current; current = current->left;
        }
    }

    return current;
}

void BinarySearchTree::getSortedSequence() {

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