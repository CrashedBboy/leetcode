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
// then sort the frequency, pick top K

class Solution {

private:
    bool pairComp(pair<int, int> p1, pair<int, int> p2) {
        
        return p1.second > p2.second;
    }

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        vector<int> results;

        if (nums.empty()) {
            return results;
        }

        map<int, int> frequency;
        map<int, int>::iterator it;
        for (int i = 0; i < nums.size(); i++) {

            if (frequency.find(nums[i]) != frequency.end()) {

                frequency[nums[i]] += 1;
            
            } else {

                frequency[nums[i]] = 1;
            }
        }

        vector<pair<int, int>> frequencyList;

        for (auto p : frequency) {
            frequencyList.push_back(p);
        }

        sort(frequencyList.begin(), frequencyList.end(), pairComp);

        for (int i = 0; i < k; i++) {
            results.push_back(frequencyList[i].first);
        }

        return results;
    }
};