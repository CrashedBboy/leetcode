// Source : https://leetcode.com/problems/daily-temperatures/
// Author : CrashedBboy
// Date   : 2020-04-14

// Questions
/********************************************************************************** 
Given a list of daily temperatures T, return a list such that,
for each day in the input, tells you how many days you would have to wait until a warmer temperature.
If there is no future day for which this is possible, put 0 instead.

For example,
given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73],
your output should be [1, 1, 4, 2, 1, 1, 0, 0].
**********************************************************************************/

// [idea 1]
// use one array of ints to record how many days to wait
// use one array of bools to denote if this element is done (no need to compare with current temp)

// time complexity: O(N^2)
// space complexity: O(N)

// [idea 2]
// during iterating the list:
//// keep calculate the temp is going up or down
//// accumulate the count of waiting days: waitingCount
//// when the temp is going up => do back-updating:
////// 'solve' the previous days which are still waiting & temp are lower than current temp
////// if (back iterating reach a unsolved day with higher temp) or (waitingCount == 0) => stop back-updating

// use one list of ints to record how many days to wait for each day
// the list is initialized with all zeros
// (zero indicates that a day is still waiting)

// how to 'solve' the waiting day:
// the answer for the day = current index - waiting day's index

// time complexity: O(N)
// space complexity: O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

        vector<int> results(T.size(), 0);

        if (T.empty()) {
            return results;
        }

        if (T.size() == 1) {

            return results;
        }

        // iterate the list, start from 2nd element
        int waitingCount = 1;
        for (int i = 1; i < T.size(); i++) {

            int diff = T[i] - T[i - 1];
            int currentTemp = T[i];

            if (diff > 0) {

                // do back-updating
                for (int j = i - 1; j >= 0, waitingCount > 0; j--) {

                    if (results[j] == 0) {

                        if (T[j] < currentTemp) {

                            results[j] = i - j;

                            waitingCount -= 1;

                        } else {

                            break;
                        }
                    }
                }
            }
            
            waitingCount += 1;
        }

        return results;
    }
};


// [another approach]
// using stack