// Source : https://leetcode.com/problems/coin-change/
// Author : CrashedBboy
// Date   : 2020-12-04

// Questions
/********************************************************************************** 

You are given coins of different denominations and a total amount of money amount.
Write a function to compute the fewest number of coins that you need to make up that 
amount. 
If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.

Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2:

Input: coins = [2], amount = 3
Output: -1

Example 3:

Input: coins = [1], amount = 0
Output: 0

Example 4:

Input: coins = [1], amount = 1
Output: 1

Example 5:

Input: coins = [1], amount = 2
Output: 2

Constraints:

* 1 <= coins.length <= 12
* 1 <= coins[i] <= 2^31 - 1
* 0 <= amount <= 10^4

**********************************************************************************/


// Idea
/********************************************************************************** 

using DP: bottom-up approach!

create an array coins_needed[amount] to store how many coins needed to fulfill the amount.

* looply do: coins_needed[amount] = min(coins_needed[amount], 1 + coins_needed[amount - coin_a])


* initialize: coins_needed[0] to be 0, coins_needed[>=1] to be (amount+1)

**********************************************************************************/

#include <vector>
#include <algorithm>

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        // input check
        if (coins.size() == 0) { return 0; }
        if (amount == 0) { return 0; }

        // number of coins needed which is impossible
        int INF_COINS = amount + 1;

        // create DP array
        vector<int> coins_needed(amount + 1, INF_COINS);
        coins_needed[0] = 0;

        for (int i = 0; i < coins_needed.size(); i++) {
            for (int c = 0; c < coins.size(); c++) {
                if ((i - coins[c]) >= 0) {
                    coins_needed[i] = min(coins_needed[i], 1 + coins_needed[i - coins[c]]);
                }
            }
        }

        // to tell whether there's solution or not
        if (coins_needed[amount] > amount) {
            return -1;
        }
        else {
            return coins_needed[amount];
        }
    }
};