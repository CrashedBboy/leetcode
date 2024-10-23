// [idea]
// use hash map to store parent pointer of each node
// use BFS (or DFS) to search P and Q
// once both P and Q are found, start using parent pointer map to trace back
// the first common parent is LCA


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        unordered_map<TreeNode*, TreeNode*> parentMap;
        parentMap[root] = NULL;

        // BFS queue
        queue<TreeNode*> bfsQueue;

        // BFS starts from root node
        bfsQueue.push(root);

        while (parentMap.count(p) == 0 || parentMap.count(q) == 0) {

            TreeNode* currentNode = bfsQueue.front();
            TreeNode* leftChild = currentNode->left;
            TreeNode* rightChild = currentNode->right;

            if (leftChild) {
                parentMap[leftChild] = currentNode;
                bfsQueue.push(leftChild);
            }

            if (rightChild) {
                parentMap[rightChild] = currentNode;
                bfsQueue.push(rightChild);
            }

            bfsQueue.pop();
        }

        TreeNode* pAncestor = p;
        while (true) {

            TreeNode* qAncestor = q;
            while (true) {

                if (pAncestor == qAncestor) {
                    return pAncestor;
                }

                if (parentMap.count(qAncestor) == 0) {
                    break;
                }
                qAncestor = parentMap[qAncestor];
            }

            if (parentMap.count(pAncestor) == 0) {
                break;
            }
            pAncestor = parentMap[pAncestor];
        }

        return root;
    }
};