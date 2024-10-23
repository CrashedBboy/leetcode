#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;
        
        unordered_map<int, int> freq;
        for (auto& n : nums) {
            freq[n] += 1;
        }

        vector<vector<int>> freqBin(nums.size(), vector<int>());

        for (auto& [key, value] : freq) {
            freqBin[value-1].push_back(key);
        }

        for (int i = freqBin.size() - 1; i >= 0; i--) {
            for (auto& n : freqBin[i]) {
                ans.push_back(n);

                if (ans.size() == k) {
                    return ans;
                }
            }
            
        }

        return ans;
    }
};