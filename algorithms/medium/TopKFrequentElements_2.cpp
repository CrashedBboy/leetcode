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
// then build max-heap using frequency
// retrieve root and heapify K times

class Heap {

private:
    vector<pair<int, int>> _list;

    void heapify() {

        if (_list.size() < 2) {
            return;
        }

        for (int i = (int)(_list.size() - 2)/2; i >= 0; i--) {

            if (i*2 + 2 == _list.size()) {

                if (_list[i*2 + 1].second > _list[i].second) {

                    swap(_list[i*2 + 1], _list[i]);
                }

            } else {

                if (_list[i*2 + 1].second > _list[i].second && _list[i*2 + 1].second >= _list[i*2 + 2].second) {

                    swap(_list[i*2 + 1], _list[i]);

                } else if (_list[i*2 + 2].second > _list[i].second && _list[i*2 + 2].second >= _list[i*2 + 1].second) {

                    swap(_list[i*2 + 2], _list[i]);
                }
            }
        }
    }

public:

    Heap (vector<pair<int, int>> list) {

        _list = list;

        heapify();
    }

    int popRoot() {

        int rootNumber = _list[0].first;

        _list[0] = _list[_list.size() - 1];

        _list.pop_back();

        heapify();

        return rootNumber;
    }
};

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

        Heap frequencyHeap(frequencyList);

        for (int i = 0; i < k; i++) {
            results.push_back(frequencyHeap.popRoot());
        }

        return results;
    }
};