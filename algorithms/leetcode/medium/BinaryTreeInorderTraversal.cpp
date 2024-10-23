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

// [another solution]
// iteration, using stack

// continusly push left node into stack until null
// pop stack => add to sequence => push it right

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

public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int> results;

        if (root == NULL) {

            return results;
        }

        stack<TreeNode*> nodeStack;
        TreeNode* currentNode = root;
        while (currentNode != NULL || !nodeStack.empty()) {

            while (currentNode != NULL) {

                nodeStack.push(currentNode);
                currentNode = currentNode->left;
            }

            currentNode = nodeStack.top();
            results.push_back(currentNode->val);
            nodeStack.pop();

            currentNode = currentNode->right;
        }

        return results;
    }
};