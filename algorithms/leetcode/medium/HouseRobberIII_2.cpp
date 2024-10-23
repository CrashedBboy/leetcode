// Source : https://leetcode.com/problems/house-robber-iii/
// Author : CrashedBboy
// Date   : 2020-05-01

// Questions
/********************************************************************************** 

The thief has found himself a new place for his thievery again. There is only one 
entrance to this area, called the "root." 
Besides the root, each house has one and only one parent house. 
After a tour, the smart thief realized that "all houses in this place forms a binary tree".
It will automatically contact the police if two directly-linked houses were broken into 
on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 

Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9

Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.

**********************************************************************************/

// [idea]
// because it's a tree (sibling houses won't be conencted), if parent is robbed, then
// child can't be robbed; if child is robbed, then parent can't be robbed.

// robbed = max (rob this level, not to rob this level)

// return [rob this node, not to robbed this node]

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
    vector<int> robNode(TreeNode* node) {

        if (node == NULL) {
            return vector<int>(2, 0);
        }

        vector<int> right = robNode(node->right);
        vector<int> left = robNode(node->left);

        vector<int> result(2, 0);

        result[0] = max(right[0], right[1]) + max(left[0], left[1]);
        result[1] = node->val + right[0] + left[0];

        return result;
    }

public:
    int rob(TreeNode* root) {

        vector<int> result = robNode(root);

        return max(result[0], result[1]);
    }
};