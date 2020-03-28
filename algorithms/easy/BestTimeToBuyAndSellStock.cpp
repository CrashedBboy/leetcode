// Source : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
// Author : CrashedBboy
// Date   : 2020-03-28

// Questions
/********************************************************************************** 

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.

Example 1:

Input: [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
             Not 7-1 = 6, as selling price needs to be larger than buying price.

Example 2:

Input: [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

**********************************************************************************/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int size = prices.size();

        if (size == 0)
        {
            return 0;
        }

        // method1: Brute force: for each element, find the maximum element in its succeeding list
        /*
        int maxProfit = 0;
        for (int i = 0; i < (size-1); i++) {
            int succeedingMax = 0;
            for (int j = i+1; j < size; j++) {
                if ( (prices[j] > prices[i]) && (prices[j] > succeedingMax)) {
                    succeedingMax = prices[j];
                }
            }
            int profit = succeedingMax-prices[i];
            if (profit > maxProfit) {
                maxProfit = profit;
            }
        }
        */
        
        // method2: keet track the minimum element and maximum profit,
        // iterate the whole list and update the 2 tracked variable
        int maxProfit = 0;
        int minPrice = INT_MAX;

        for (int i = 0; i < priceSize; i++) {

            if (prices[i] < minPrice) {

                minPrice = prices[i];

            } else {

                int profit = (prices[i] - minPrice);

                if (profit > maxProfit) {

                    maxProfit = profit;
                }
            }
        }

        return maxProfit;
    }
};