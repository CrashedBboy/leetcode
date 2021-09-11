#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        // solution 1
        int kth;

        make_heap(nums.begin(), nums.end()); // heapify
        for (int i = 0; i < k; i++) {
            
            pop_heap(nums.begin(), nums.end()); // swap root and the last one, than heapify

            kth = nums.back();
            nums.pop_back();
        }

        return kth;

        // solution 2
        //priority_queue<int> maxHeap {greater<int>(), nums}; // {...} => initializer_list
        // priority_queue<int> pq3 {std::less<int>(), nums};
        // for (int i = 0; i < k; i++) {
        //     maxHeap.pop();
        // }

        // return maxHeap.top();
    }
};