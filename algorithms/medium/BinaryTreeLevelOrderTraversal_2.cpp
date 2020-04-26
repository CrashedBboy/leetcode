// Source : https://leetcode.com/problems/binary-tree-level-order-traversal/
// Author : CrashedBboy
// Date   : 2020-04-27

// Questions
/********************************************************************************** 
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

**********************************************************************************/

// [idea]
// preorder traversal
// it would act like DFS, but the order of pushing elements of different levels is not 
// limited (not necessary be BFS)
// but the order of elements in the same level matters

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
    void traverse(TreeNode* node, int level, vector<vector<int>>& results) {

        if (node == NULL) { return; }

        // if list of the level doesn't exist
        if (results.size() == level) {
            results.push_back(vector<int>());
        }

        results[level].push_back(node->val);
        
        traverse(node->left, level + 1, results);
        traverse(node->right, level + 1, results);
    }

public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> results;

        if (root == NULL) {
            return results;
        }

        traverse(root, 0, results);

        return results;
    }
};