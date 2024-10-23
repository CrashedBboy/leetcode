#include <stack>

using namespace std;

class BinaryTreeNode {

public:

    int val;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int x, BinaryTreeNode* left, BinaryTreeNode* right);
    BinaryTreeNode(int x);
    BinaryTreeNode();

private:

};

class BinarySearchTree {

public:
    BinarySearchTree();
    BinarySearchTree(bool unique);
    void insert(int x);
    static BinaryTreeNode* minValueNode(BinaryTreeNode* root, BinaryTreeNode* targetParent);
    void erase(int x);
    bool contains(int x);
    BinaryTreeNode* search(int x, BinaryTreeNode* targetParent);
    void getSortedSequence();

private:
    BinaryTreeNode* root;
    BinaryTreeNode* fakeNull;
    bool uniqueKey;
};