// Source : https://leetcode.com/problems/task-scheduler/
// Author : CrashedBboy
// Date   : 2020-05-07

// Questions
/********************************************************************************** 
Given a char array representing tasks CPU need to do.
It contains capital letters A to Z where different letters represent different tasks.
Tasks could be done without original order.
Each task could be done in one interval.
For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks,
there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.

Constraints:

* The number of tasks is in the range [1, 10000].
* The integer n is in the range [0, 100].

**********************************************************************************/

// [idea]
// !! task with most remaining has the highest priority to be executed !!
// Because of the constraint of cooling interval, tasks with larger amount will contribute
// to the idle time, we need to execute the large-remaining tasks whose cooling has been finished.

// now we know we need to execute task with largest remaining first, but what can we do during its cooling?
// => execute the 2nd largest task, execute the 3rd lrgest task, ... until there's no task can be executed,
// then we simply increase execution time without execute any task

// when the cooling is done, re-sorting the remaining array (to find out which task has most remaining now)

// execute task i => remaining[i] -= 1

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> remaining(26, 0);

        for (char c : tasks) {
            remaining[c - 'A'] += 1;
        }

        sort(remaining.begin(), remaining.end());

        // accumulated execution time
        int time = 0;

        // last element in array stores the maximum
        // it is zero means all tasks have been executed
        while (remaining[25] > 0) {

            int ithExecuted = 0;
            while (ithExecuted <= n) {

                // if the largest task is completed-finished,
                // we don't have to do cooling anymore
                if (remaining[25] == 0) {
                    break;
                }

                // if i is in the range of letters and the i-th largest task remaining > 0
                if (ithExecuted < 26 && remaining[25 - ithExecuted] > 0) {
                    remaining[25 - ithExecuted] -= 1;
                }

                ithExecuted += 1; // do cooling
                time += 1; // accmulate execution time
            }

            // re-sort to find the largest remaining
            sort(remaining.begin(), remaining.end());
        }

        return time;
    }
};