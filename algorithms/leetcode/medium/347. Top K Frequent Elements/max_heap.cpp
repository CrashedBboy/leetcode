#include <queue>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef pair<int, int> NumFreq;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> ans;

        unordered_map<int, int> freq;
        for (auto& n : nums) {
            freq[n] += 1;
        }

        auto custom_cmp = [](NumFreq a, NumFreq b) { return a.second < b.second; };

        priority_queue<NumFreq, vector<NumFreq>, decltype(custom_cmp)> maxHeap {custom_cmp};
        for (auto& f : freq) {
            maxHeap.push(f);
        }

        for (int i = 0; i < k; i++) {
            NumFreq f = maxHeap.top(); maxHeap.pop();
            ans.push_back(f.first);
        }

        return ans;
    }
};

int main () {

    vector<int> nums = {1};
    int k = 1;

    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);

    for (auto& a : ans) {
        cout << a << ", ";
    }
    cout << endl;

    return 0;
}