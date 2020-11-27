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

#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Solution {

private:

    int INDEX_PADDING = 1;

    int doTransaction(vector<int>& prices, vector<vector<vector<int>>>& memo, int currentIndex, int stockHolding, int stepsFromLatestSell) {

        // borundary check
        if (currentIndex == prices.size()) {
            return 0;
        }


        if (stepsFromLatestSell > 1) {
            if (memo[currentIndex][stockHolding+INDEX_PADDING][1] != NULL) {
                return memo[currentIndex][stockHolding+INDEX_PADDING][1];
            }
        } else {
            if (memo[currentIndex][stockHolding+INDEX_PADDING][0] != NULL) {
                return memo[currentIndex][stockHolding+INDEX_PADDING][0];
            }
        }
        

        int maxProfit = numeric_limits<int>::min();
        int p;
        if (stockHolding != -1) {

            // can sell
            p = (prices[currentIndex] - prices[stockHolding]) + doTransaction(prices, memo, (currentIndex+1), -1, 1);
            maxProfit = max(maxProfit, p);

            // can do nothing
            p = doTransaction(prices, memo, (currentIndex+1), stockHolding, (stepsFromLatestSell+1));
            maxProfit = max(maxProfit, p);

        } else {

            if (stepsFromLatestSell > 1) {

                // can buy
                p = doTransaction(prices, memo, (currentIndex+1), currentIndex, (stepsFromLatestSell+1));
                maxProfit = max(maxProfit, p);

                // can do nothing
                p = doTransaction(prices, memo, (currentIndex+1), stockHolding, (stepsFromLatestSell+1));
                maxProfit = max(maxProfit, p);

            } else {

                // can do: nothing
                p = doTransaction(prices, memo, (currentIndex+1), stockHolding, (stepsFromLatestSell+1));
                maxProfit = max(maxProfit, p);
            }
        }

        if (stepsFromLatestSell > 1) {
            memo[currentIndex][stockHolding+INDEX_PADDING][1] = maxProfit;
        } else {
            memo[currentIndex][stockHolding+INDEX_PADDING][0] = maxProfit;
        }

        return maxProfit;
    }

public:
    int maxProfit(vector<int>& prices) {

        int N = prices.size();

        vector<vector<vector<int>>> memo(N+1, vector<vector<int>>(N+1+INDEX_PADDING, vector<int>(2, NULL)));

        return doTransaction(prices, memo, 0, -1, 2);
    }
};