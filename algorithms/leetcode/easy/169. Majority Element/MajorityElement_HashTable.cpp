#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> count;

        for (auto& n : nums) {
            count[n] += 1;

            if (count[n] > (nums.size()/2)) {
                return n;
            }
        }
    }
};


int main () {

    vector<int> inputs = {2,2,1,1,1,2,2};

    Solution sol;
    
    cout << sol.majorityElement(inputs) << endl;

    return 0;
}