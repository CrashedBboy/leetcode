#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());

        return nums[(int)(nums.size()/2)];
    }
};


int main () {

    vector<int> inputs = {2,2,1,1,1,2,2};

    Solution sol;
    
    cout << sol.majorityElement(inputs) << endl;

    return 0;
}