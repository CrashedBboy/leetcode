// idea1: use hash table

// idea2: use sorting


#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
        if (nums.size() < 2) {
            return false;
        }
        
        bool duplicated = false;
        sort(nums.begin(), nums.end());
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i-1]) {
                duplicated = true;
                break;
            }
        }
        
        return duplicated;
    }
};