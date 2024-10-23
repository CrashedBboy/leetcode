#include <algorithm>
#include <queue>

typedef pair<TreeNode*, int> NodeLevel;

using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {

        int maxValue = 0;

        if (root == nullptr) {
            return maxValue;
        }

        queue<pair<TreeNode*, int>> bfsQueue;

        bfsQueue.push(NodeLevel(root, 1));

        while (!bfsQueue.empty()) {
            NodeLevel nl = bfsQueue.front(); bfsQueue.pop();

            TreeNode* n = nl.first;
            int level = nl.second;

            if (n != nullptr) {
                if (level > maxValue) {
                    maxValue = level;
                }

                bfsQueue.push(NodeLevel(n->left, level+1));
                bfsQueue.push(NodeLevel(n->right, level + 1));
            }
        }

        return maxValue;
    }
};