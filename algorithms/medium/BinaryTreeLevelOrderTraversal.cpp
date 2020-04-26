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
// use BFS traversal: queue

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class LevelNode {

private:
    TreeNode* _node;
    int _level;

public:

    LevelNode(TreeNode* node, int level) {

        _node = node;
        _level = level;
    }

    int getLevel() { return _level; }

    TreeNode* getNode() { return _node; }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> results;

        if (root == NULL) {

            return results;
        }

        queue<LevelNode> bfsQueue;

        LevelNode rootNode(root, 0);
        bfsQueue.push(rootNode);

        while (!bfsQueue.empty()) {

            LevelNode front = bfsQueue.front();
            TreeNode* n = front.getNode();
            int level = front.getLevel();

            // if level list doesn't exist
            if (results.size() == front.getLevel()) {

                vector<int> newLevel = { n->val };
                results.push_back(newLevel);
            
            } else {

                results[level].push_back(n->val);
            }

            if (n->left != NULL) {
                LevelNode newLevelNode(n->left, level + 1);
                bfsQueue.push(newLevelNode);
            }

            if (n->right != NULL) {
                LevelNode newLevelNode(n->right, level + 1);
                bfsQueue.push(newLevelNode);
            }

            bfsQueue.pop();
        }

        return results;
    }
};