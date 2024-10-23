// Source : https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
// Author : CrashedBboy
// Date   : 2020-11-25

// Questions
/*********************************************************************************************

Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7

*********************************************************************************************/

// Idea
/*********************************************************************************************

Recursive divide-n-conquer
https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/discuss/947448/2-Solution-or-Detailed-Explanation-with-Code

Key: 1st node of pre-order sequence is root of tree

*********************************************************************************************/

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

private:

    TreeNode* growTree(vector<int>& preorder, vector<int>& inorder, int inStart, int inEnd, int preRootIndex) {

        // boundry check
        if (inStart > inEnd) {
            return NULL;
        }

        // find index of root in in-order sequence
        int inRootIndex = inStart;
        while (inorder[inRootIndex] != preorder[preRootIndex]) {
            inRootIndex += 1;
        }

        TreeNode* root = new TreeNode(preorder[preRootIndex]);

        root->left = growTree(preorder, inorder, inStart, (inRootIndex-1), (preRootIndex+1));
        root->right = growTree(preorder, inorder, (inRootIndex+1), inEnd, preRootIndex + (inRootIndex-inStart+1));

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        // devide & conquer
        return growTree(preorder, inorder, 0, inorder.size() - 1, 0);
    }
};