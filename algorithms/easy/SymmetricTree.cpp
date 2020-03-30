// Source : https://leetcode.com/problems/symmetric-tree/
// Author : CrashedBboy
// Date   : 2020-03-30

// Questions
/********************************************************************************** 
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

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
    bool isSymmetric(TreeNode* root) {

        // traversal the left subtree with BFS (left-to-right order), and right subtree with BFS (right-to-left order). 
        // the traversal result will be stored into a sequence respectively, then compare if two sequence are identical


        if (root == NULL) {
            return true;
        }

        TreeNode* nullNode = new TreeNode(0);

        std::queue<TreeNode*> leftBFSQueue;
        std::queue<TreeNode*> rightBFSQueue;

        std::vector<int> leftTraversalSequence;
        std::vector<bool> leftTraversalNullSequence;
        std::vector<int> rightTraversalSequence;
        std::vector<bool> rightTraversalNullSequence;

        if (root->left != NULL) {
            leftBFSQueue.push(root->left);
        } else {
            leftBFSQueue.push(nullNode);
        }

        if (root->right != NULL) {
            rightBFSQueue.push(root->right);
        } else {
            rightBFSQueue.push(nullNode);
        }

        while(!leftBFSQueue.empty()) {

            TreeNode *node = leftBFSQueue.front();
            leftBFSQueue.pop();

            if (node == nullNode) {

                leftTraversalSequence.push_back(0);
                leftTraversalNullSequence.push_back(true);

                continue;
            
            } else {

                leftTraversalSequence.push_back(node->val);
                leftTraversalNullSequence.push_back(false);
            }

            if (node->left == NULL) {
                leftBFSQueue.push(nullNode);
            } else {
                leftBFSQueue.push(node->left);
            }
            
            if (node->right == NULL) {
                leftBFSQueue.push(nullNode);
            } else {
                leftBFSQueue.push(node->right);
            }
        }

        while(!rightBFSQueue.empty()) {

            TreeNode *node = rightBFSQueue.front();
            rightBFSQueue.pop();

            if (node == nullNode) {

                rightTraversalSequence.push_back(0);
                rightTraversalNullSequence.push_back(true);

                continue;
            
            } else {

                rightTraversalSequence.push_back(node->val);
                rightTraversalNullSequence.push_back(false);
            }

            if (node->right == NULL) {
                rightBFSQueue.push(nullNode);
            } else {
                rightBFSQueue.push(node->right);
            }

            if (node->left == NULL) {
                rightBFSQueue.push(nullNode);
            } else {
                rightBFSQueue.push(node->left);
            }
        }

        int rightSequenceSize = rightTraversalSequence.size();
        int leftSequenceSize = leftTraversalSequence.size();

        if (rightSequenceSize != leftSequenceSize) {
            return false;
        }

        for (int i = 0; i < rightSequenceSize; i++) {
            if ((rightTraversalSequence[i] != leftTraversalSequence[i]) 
                || (rightTraversalNullSequence[i] != leftTraversalNullSequence[i])) {

                return false;
            }
        }

        return true;
    }
};