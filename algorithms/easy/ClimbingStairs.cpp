// Source : https://leetcode.com/problems/diameter-of-binary-tree/
// Author : CrashedBboy
// Date   : 2020-03-28

// Questions
/********************************************************************************** 
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Note: Given n will be a positive integer.

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

**********************************************************************************/

// use recursion: f(n) = f(n-1) + f(n-2) with memorize technique

class Solution {
public:

    vector<int> steps;
    bool initialized = false;
    int climbStairs(int n) {

        if (n < 0) {
            return 0;
        }

        if (n == 0) {
            return 1;
        }

        if (this->initialized == false) {
            this->initialized = true;
            this->steps.resize(n+1);

            // mark all with -1 to represent not-visited
            for (int i = 0; i < n+1; i++) {
                this->steps[i] = -1;
            }

        } else {
            
            if (this->steps[n] != -1) {
                return this->steps[n];
            }
        }

        int result = climbStairs(n-1) + climbStairs(n-2);
        this->steps[n] = result;
        return result;
    }
};