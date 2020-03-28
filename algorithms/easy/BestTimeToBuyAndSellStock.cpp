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