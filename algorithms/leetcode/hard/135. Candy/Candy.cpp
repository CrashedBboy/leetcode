#include <vector>

class Solution {
public:
    int candy(vector<int>& ratings) {
        
        int ans = ratings.size();

        vector<int> candies (ratings.size(), 1);

        // forward iteration
        for (int i = 1; i < ratings.size(); i++) {
            if ((ratings[i] > ratings[i-1]) && (candies[i] <= candies[i-1])) {
                int increment = candies[i-1] - candies[i] + 1;
                candies[i] += increment;
                ans += increment;
            }
        }

        // backward iteration
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if ((ratings[i] > ratings[i+1]) && (candies[i] <= candies[i+1])) {
                int increment = candies[i+1] - candies[i] + 1;
                candies[i] += increment;
                ans += increment;
            }
        }

        return ans;
    }
};