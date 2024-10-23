#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define NULL_NODE -200

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {

        // IDEA:
        // traversal the left subtree with BFS (left-to-right order), and right subtree with BFS (right-to-left order). 
        // the traversal result will be stored into a sequence respectively, then compare if two sequence are identical

        vector<int> leftSeq;
        vector<int> rightSeq;

        getLevelOrderSequence(root->left, leftSeq, false);
        getLevelOrderSequence(root->right, rightSeq, true);

        if (leftSeq.size() != rightSeq.size()) {
            return false;
        }
        else {
            for (int idx = 0; idx < leftSeq.size(); idx++) {
                if (leftSeq[idx] != rightSeq[idx]) {
                    return false;
                }
            }
        }

        return true;
    }

private:

    void getLevelOrderSequence(TreeNode* root, vector<int>& sequence, bool reversed) {

        if (root == nullptr) {
            return;
        }

        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);

        while (!bfsQueue.empty()) {

            TreeNode* node = bfsQueue.front();
            bfsQueue.pop();

            if (node == nullptr) {
                sequence.push_back(NULL_NODE);
            }
            else {
                sequence.push_back(node->val);

                if (reversed) {
                    bfsQueue.push(node->left);
                    bfsQueue.push(node->right);
                }
                else {
                    bfsQueue.push(node->right);
                    bfsQueue.push(node->left);
                }
            }
        }
    }

};