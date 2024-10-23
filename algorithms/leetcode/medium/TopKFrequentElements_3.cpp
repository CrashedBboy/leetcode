// Source : https://leetcode.com/problems/top-k-frequent-elements/
// Author : CrashedBboy
// Date   : 2020-04-19

// Questions
/********************************************************************************** 
Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Note:
* You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
* Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
**********************************************************************************/

// [idea]
// use hast table to store each number's frequency
// then use bucket sort -> bucket[i] = list represents numbers who has frequency i 

class Solution {

private:

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> results;

        if (nums.empty()) {
            return results;
        }

        unordered_map<int, int> frequencyTable;
        for (int i = 0; i < nums.size(); i++) {

            frequencyTable[nums[i]] += 1;
        }

        // initilaize the buckets (frequency range: 0 ~ N)
        vector<vector<int>> frequencyBuckets(nums.size() + 1);

        for (auto p : frequencyTable) {

            frequencyBuckets[p.second].push_back(p.first);
        }

        for (int i = frequencyBuckets.size() - 1; i >= 0; i--) {

            if (!frequencyBuckets[i].empty()) {

                for (int j = 0; j < frequencyBuckets[i].size(); j++) {

                    results.push_back(frequencyBuckets[i][j]);

                    if (results.size() == k) {

                        return results;
                    }
                }
            }
        }

        return results;
    }
};