// Source : https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
// Author : CrashedBboy
// Date   : 2020-11-21

// Questions
/********************************************************************************** 
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

**********************************************************************************/

// idea
/********************************************************************************** 

the question's about pre-order --> center + left subtree seq + right subtree seq

in order to concat left seq and right seq without diving into right most leaf of left seq,
this solution is about 'reverse pre-order' !

it's needs a tmp pointer pointing to previous visited node: prev

flatten(right)
flatten(left)
root->right = prev
root->left = NULL
prev = root


**********************************************************************************/


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

    TreeNode* prev;

public:
    
    void flatten(TreeNode* root) {
        
        // boundry check!
        if (root == NULL) {
            return;
        }

        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};