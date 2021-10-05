#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<int> ans;

        unordered_map<int, int> freq;
        for (auto& n : nums) {
            freq[n] += 1;
        }

        vector<pair<int, int>> freqList;
        for (auto& f : freq) {
            freqList.push_back(f);
        }

        // do quick select
        int left = 0; int right = freqList.size()-1; int pivot; int swapTo;
        while (true) {
            pivot = right; swapTo = left;
            for (int i = left; i < right; i++) {
                if (freqList[i].second > freqList[pivot].second) {
                    swap(freqList[i], freqList[swapTo]);
                    swapTo += 1;
                }
            }
            swap(freqList[pivot], freqList[swapTo]);

            if (swapTo == (k-1)) {
                for (int i = 0; i < k; i++) {
                    ans.push_back(freqList[i].first);
                }
                break;
            }
            else if (swapTo  > (k-1)) {
                right = swapTo - 1;
            }
            else {
                left = swapTo + 1;
            }
        }

        return ans;
    }
};

int main () {

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;

    Solution sol;
    vector<int> ans = sol.topKFrequent(nums, k);

    for (auto& a : ans) {
        cout << a << ", ";
    }
    cout << endl;

    return 0;
}