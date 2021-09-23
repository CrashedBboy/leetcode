#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (const vector<int>& a, const vector<int>& b) {
    return (a[1] < b[1]);
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), cmp);

        // initialize
        int count = 1;
        int end = intervals[0][1]; // we don't care about 'start'

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= end) {
                count += 1;
                end = intervals[i][1];
            }
        }

        return (intervals.size() - count);
    }
};
