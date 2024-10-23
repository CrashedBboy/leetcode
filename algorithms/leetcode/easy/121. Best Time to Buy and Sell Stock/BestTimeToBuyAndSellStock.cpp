#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int minPrice = INT_MAX;
        int profit = 0;

        for (auto& p : prices) {

            if (p < minPrice) {
                minPrice = p;
            }
            else {
                profit = max(profit, (p - minPrice));
            }
        }

        return profit;
    }
};

int main () {

    vector<int> prices = {5, 2, 4, 3, 7, 1};

    Solution sol;
    cout << sol.maxProfit(prices) << endl;

    return 0;
}