// PLEASE DO NOT SOLVE IT USING DP!!

#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() <= 1) {
            return 0;
        } 

        int profit = 0;
        int valley = 0, peak = 0;

        for (int i = 1; i < prices.size(); i++) {

            if (prices[i] > prices[i-1]) {
                peak = i;
            }
            else if (prices[i] < prices[i-1]) {
                if (peak > valley) {
                    profit += (prices[peak] - prices[valley]);
                }
                peak = valley = i;
            }
        }

        if (peak != valley) {
            profit += (prices[peak] - prices[valley]);
        }

        return profit;
    }
};

int main () {

    vector<int> prices = {7, 1, 5, 3, 6, 4};

    Solution sol;

    cout << "Max profit: " << sol.maxProfit(prices) << endl;

    return 0;
}