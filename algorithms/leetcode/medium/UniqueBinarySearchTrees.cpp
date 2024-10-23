// Source : https://leetcode.com/problems/unique-binary-search-trees/
// Author : CrashedBboy
// Date   : 2020-04-30

// Questions
/********************************************************************************** 

Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5

Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

**********************************************************************************/

// [idea]
// using DP with memoization

// result: trees[N] (number of unique binary trees from N nodes)

// set trees[0] = 1, trees[1] = 1
// compute trees[i], i = 2 ~ N:      (dynamic programming)
//// trees[i] += trees[j] * trees[i - j - 1], j = 0 ~ (i-1)
//// (iteratively pick j-th node as root, and the number of unique trees will be left * right)


class Solution {

public:
    int numTrees(int n) {

        vector<int> trees(n+1, 0);

        trees[0] = 1;
        trees[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                trees[i] += trees[j] * trees[(i-1) - j];
            }
        }
        
        return trees[n];
    }
};