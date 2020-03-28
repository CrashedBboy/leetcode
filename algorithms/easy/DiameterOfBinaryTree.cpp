// Source : https://leetcode.com/problems/diameter-of-binary-tree/
// Author : CrashedBboy
// Date   : 2020-03-28

// Questions
/********************************************************************************** 
Given a binary tree, you need to compute the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest path between any two nodes in a tree.
This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

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
    vector<int> lengths;

    // return the depth of subtree rooted at parameter node
    int computeLengthOnNode(TreeNode *root) {

        if (root == NULL) {
            return 0;
        }

        int rightDepth = computeLengthOnNode(root->right);
        int leftDepth = computeLengthOnNode(root->left);
        int depth = max(leftDepth, rightDepth) + 1;

        // save the length of path which use current node 
        this->lengths.push_back(rightDepth + leftDepth);

        return depth;
    }

    int diameterOfBinaryTree(TreeNode *root) {

        if (root == NULL) {

            return 0;
        }

        // get all path length
        int l = computeLengthOnNode(root);

        int longest = 0;
        for (int i = 0; i < this->lengths.size(); i++) {

            if (this->lengths[i] > longest) {
                longest = this->lengths[i];
            }
        }

        return longest;
    }
};
