// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
// Author : CrashedBboy
// Date   : 2020-11-26

// Questions
/********************************************************************************** 

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.
You may complete as many transactions as you like (ie, buy one and sell one share of 
the stock multiple times) with the following restrictions:

1. You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
2. After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

**********************************************************************************/

// Idea
/********************************************************************************** 
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/discuss/75928/Share-my-DP-solution-(By-State-Machine-Thinking)

There're 3 actions in total:
1. do nothing (= cooldown)
2. buy stock
3. sell stock

There're 3 states in total:
1. S0: holding no stock, but can buy at the next price
2. S1: holding a stock
3. S2: holding no stock, but cannot buy at the next price (in cooldown)

Dynamic Programming:

s0[i] = profit earned so far at the i-th price and be at state of S0

**********************************************************************************/

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {

public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() == 0) return 0;

        vector<int> s0(prices.size(), 0);
        vector<int> s1(prices.size(), 0);
        vector<int> s2(prices.size(), 0);

        // initialize
        s0[0] = 0;
        s1[0] = -prices[0]; // already bought at price 0-th
        s2[0] = numeric_limits<int>::min();

        for (int i = 1; i < prices.size(); i++) {

            s0[i] = max(s0[i-1], s2[i-1]);
            s1[i] = max(s1[i-1], s0[i-1] - prices[i]);
            s2[i] = s1[i-1] + prices[i];
        }

        return max(s0[prices.size()-1], s2[prices.size()-1]);
    }
};