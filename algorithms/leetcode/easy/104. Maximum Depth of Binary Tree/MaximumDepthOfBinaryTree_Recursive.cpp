// Source : https://leetcode.com/problems/maximum-depth-of-binary-tree/
// Author : CrashedBboy
// Date   : 2020-03-11

// Questions
/********************************************************************************** 
* 
* Given a binary tree, find its maximum depth.
*
* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
*
* Example:
*
* Given binary tree [3,9,20,null,null,15,7],
*
*    3
*   / \
*  9  20
*    /  \
*   15   7
* 
* Output:
*
* return its depth = 3
*  
* 
* Note: The merging process must start from the root nodes of both trees.
*
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
    int maxDepth(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }

        // using recursion to traverse to tree’s leaf and add up depth

        return 1 + std::max(maxDepth(root->right), maxDepth(root->left));
    }
};