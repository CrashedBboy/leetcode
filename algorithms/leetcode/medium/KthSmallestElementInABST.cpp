#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        
        // idea: in-order traversal

        vector<int> sequence;
        inOrderTraverse(root, sequence);

        return sequence[k-1];
    }

private:
    void inOrderTraverse(TreeNode* root, vector<int>& sequence) {

        if (root == NULL) {
            return;
        }

        inOrderTraverse(root->left, sequence);
        sequence.push_back(root->val);
        inOrderTraverse(root->right, sequence);
    }
};



