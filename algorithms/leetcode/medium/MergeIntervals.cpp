// Source : https://leetcode.com/problems/merge-intervals/
// Author : CrashedBboy
// Date   : 2020-04-05

// Questions
/********************************************************************************** 
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
NOTE: input types have been changed on April 15, 2019. Please reset to default code definition to get new method signature.

**********************************************************************************/

class Solution {

private:
    bool isOverlapped(vector<int>& interval1, vector<int>& interval2) {

        if ( (interval1[0] <= interval2[0] && interval2[0] <= interval1[1])
            || (interval1[0] <= interval2[1] && interval2[1] <= interval1[1])
            || (interval2[0] <= interval1[0] && interval1[0] <= interval2[1])
            || (interval2[0] <= interval1[1] && interval1[1] <= interval2[1])) {

                return true;
            }
        return false;
    }

public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // definition of overlapping
        // [start1, end1], [start2, end2]
        // 1. start1 <= start2 && start2 <= end1 
        // 2. start1 <= end2 && end2 <= end1
        // 3. start2 <= start1 && start1 <= end2
        // 4. start2 <= end1 && end1 <= end2

        vector<vector<int>> mergedIntervals;

        // use a hash table to record which has been merged (then can skip it)
        map<int, bool> merged;

        int intervalSize = intervals.size();

        if (intervalSize == 0) {
            return mergedIntervals;
        }

        // if any pair of interval merged, mergeCount += 1
        // if mergeCount == 0 in this recursion round => there's no intervals overlapped
        int mergeCount = 0;

        for (int i = 0; i < intervalSize; i++) {

            // skip those intervals which has been merged
            if (merged.count(i) > 0) {
                continue;
            }

            int lowerBound = intervals[i][0];
            int upperBound = intervals[i][1];

            // find the overlapped in the rest of intervals
            for (int j = i + 1; j < intervalSize; j++) {

                if (merged.count(j) > 0) {
                    continue;
                }

                if (isOverlapped(intervals[i], intervals[j]) == true) {
                    mergeCount += 1;

                    merged[j] = true;
                    lowerBound = min(lowerBound, intervals[j][0]);
                    upperBound = max(upperBound, intervals[j][1]);
                }
            }

            vector<int> newInterval;
            newInterval.push_back(lowerBound);
            newInterval.push_back(upperBound);

            mergedIntervals.push_back(newInterval);
        }

        if (mergeCount == 0) {

            return mergedIntervals;

        } else {

            // some intervals may be still overlapped
            return merge(mergedIntervals);
        } 
    }
};