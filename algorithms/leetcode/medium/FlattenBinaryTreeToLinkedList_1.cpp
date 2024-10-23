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

pre-order flatten! --> center(root) + left subtree sequence + right subtree sequence
                                      ---------------------   ---------------------
                                          (recursion)             (recusrion)

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
public:

    TreeNode* concatLinkedList(TreeNode* leftSequence, TreeNode* rightSequence) {

        if (leftSequence == NULL) {
            return rightSequence;
        }

        // traverse to right most leaf: A
        TreeNode* rightMostLeaf = leftSequence;
        while (rightMostLeaf->right != NULL) {
            rightMostLeaf = rightMostLeaf->right;
        }

        // concat!
        rightMostLeaf->right = rightSequence;

        return leftSequence;
    }

    TreeNode* convert2LinkedList(TreeNode* root) {

        // boundry check!
        if (root == NULL) {
            return root;
        }

        // leaf node check!
        if (root->left == NULL && root->right == NULL) {
            return root;
        }

        // left sequence
        TreeNode* leftSequence = convert2LinkedList(root->left);

        // right sequence
        TreeNode* rightSequence = convert2LinkedList(root->right);

        // concat left & right sequences
        TreeNode* concatenated_sequence = concatLinkedList(leftSequence, rightSequence);

        root->right = concatenated_sequence;
        root->left = NULL; // remember to set left to NULL

        return root;
    }
    
    void flatten(TreeNode* root) {
        
        root = convert2LinkedList(root);
    }
};