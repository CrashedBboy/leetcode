// Source : https://leetcode.com/problems/merge-two-binary-trees/
// Author : CrashedBboy
// Date   : 2020-03-08

// Questions
/********************************************************************************** 
* 
* Given two binary trees and imagine that when you put one of them to cover the other,
* some nodes of the two trees are overlapped while the others are not.

* You need to merge them into a new binary tree. The merge rule is that if two nodes overlap,
* then sum node values up as the new value of the merged node.
* Otherwise, the NOT null node will be used as the node of new tree.
*
* Example 1:
*
* Input: 
* 	Tree 1                     Tree 2                  
*           1                         2                             
*          / \                       / \                            
*         3   2                     1   3                        
*        /                           \   \                      
*       5                             4   7                  
* Output: 
* Merged tree:
* 	     3
* 	    / \
* 	   4   5
* 	  / \   \ 
* 	 5   4   7
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
 *
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     // this is class constructor, check https://docs.microsoft.com/zh-tw/cpp/cpp/constructors-cpp?view=vs-2019
 * };
 */
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        
        // if tree t1 doesn't have node (NULL) in this level of branch
        if (!t1) {
            return t2;
        }
        
        // if tree t2 doesn't have node (NULL) in this level of branch
        if (!t2) {
            return t1;
        }
        
        t1->val += t2->val;
        
        // do recursion to complete the merging of their children
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        
        // after all the recursive merging has been completed, return root node of tree t1
        return t1;
    }
};