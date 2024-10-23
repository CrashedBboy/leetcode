// Source : https://leetcode.com/problems/permutations/
// Author : CrashedBboy
// Date   : 2020-04-16

// Questions
/********************************************************************************** 
Given a collection of distinct integers, return all possible permutations.

Example:

Input: [1,2,3]
Output:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
**********************************************************************************/

// [idea]
// iterately choose a number as 1st element
//// iterately choose a number from remains as 2nd element
////// iterately choose a number from remains as 3rd element
/////// ... and so on, until choose the only one remained as Nth element

// use stack to store the sequence

class Solution {

private:

    void grow(vector<int>& nums, vector<bool>& occupied, vector<int>& sequence, vector<vector<int>>& results) {

        // pick a element from 'unoccupied', push it into sequence
        for (int i = 0; i < nums.size(); i++) {

            if (occupied[i] == false) {

                // label the element as occupied
                occupied[i] = true;
                sequence.push_back(nums[i]);

                // if length of pushed sequence is equal to nums.size(), push sequence to result
                if (sequence.size() == nums.size()) {

                    results.push_back(sequence);

                } else {

                    // if not, keep doing recursion
                    grow(nums, occupied, sequence, results);
                }

                // to restore the changes

                // pop back of sequence at the end
                sequence.pop_back();
                // label the element as not occupied
                occupied[i] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> results;

        if (nums.empty()) {
            return results;
        }
        
        vector<bool> occupied(nums.size(), false);
        vector<int> sequence;

        grow(nums, occupied, sequence, results);

        return results;
    }
};