#include <iostream>
#include <unordered_map>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    int pathSum(TreeNode* root, int targetSum) {
        
        unordered_map<int, int> sumCount; // key: sum, value: count of the sum
        // sumCount[K] = M at node i : when summing from the start to node i, there're total M times that the sum == K

        sumCount[0] = 1;

        return helper(root, 0, targetSum, sumCount);
    }


private:

    int helper(TreeNode* root, int currentSum, int targetSum, unordered_map<int, int>& sumCount) {

        if (root == nullptr) {
            return 0;
        }

        currentSum += root->val;

        int res = currentSum - targetSum;
        int resCount = sumCount[res];
        sumCount[currentSum] += 1;

        int sumCountLeft = helper(root->left, currentSum, targetSum, sumCount);
        int sumCountRight = helper(root->right, currentSum, targetSum, sumCount);

        sumCount[currentSum] -=1; // backtracking (reset any change)

        return resCount + sumCountLeft + sumCountRight;
    }
};