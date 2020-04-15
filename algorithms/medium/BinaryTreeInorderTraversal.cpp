// Source : https://leetcode.com/problems/binary-tree-inorder-traversal/
// Author : CrashedBboy
// Date   : 2020-04-15

// Questions
/********************************************************************************** 
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
**********************************************************************************/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

private:

    void traverse(TreeNode* node, vector<int>* sequence) {

        if (node == NULL) {
            return;
        }

        traverse(node->left, sequence);
        sequence->push_back(node->val);
        traverse(node->right, sequence);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> sequence;
        
        if (root == NULL) {
            return sequence;
        }

        traverse(root, &sequence);

        return sequence;
    }
};