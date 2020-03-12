// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : CrashedBboy
// Date   : 2020-03-12

// Questions
/********************************************************************************** 

Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1

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
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == NULL) { return root; }
        
        std::swap(root->right, root->left);

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        return root;

    }
};