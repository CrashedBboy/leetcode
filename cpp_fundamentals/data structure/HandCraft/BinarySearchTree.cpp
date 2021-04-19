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
    BinarySearchTree() : root(nullptr) {
        fakeNull = new BinaryTreeNode(-1);
    }

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

    static BinaryTreeNode* minValueNode(BinaryTreeNode* root, BinaryTreeNode* targetParent) {

        BinaryTreeNode* current = root;
        while (current && current->left != nullptr) {
            targetParent = current;
            current = current->left;
        }

        return current;
    }

    // erase the first found
    void erase(int x) {

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

    bool contains(int x) {

        BinaryTreeNode* current = root;

        while (current != nullptr) {

            if (x == current->val) { return true; }
            else if (x > current->val) { current = current->right; }
            else if (x < current->val) { current = current->left; }
        }

        return false;
    }

    BinaryTreeNode* search(int x, BinaryTreeNode* targetParent) {

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
    BinaryTreeNode* fakeNull;
};

int main() {

    BinarySearchTree bst;

    bst.insert(10);
    bst.insert(15);
    bst.insert(5);

    bst.getSortedSequence();

    bst.erase(10);
    bst.getSortedSequence();

    bst.erase(15);
    bst.getSortedSequence();

    bst.erase(5);
    bst.getSortedSequence();


    return 0;
}