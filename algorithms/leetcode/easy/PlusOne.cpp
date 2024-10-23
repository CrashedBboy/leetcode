// Source : https://leetcode.com/problems/plus-one/
// Author : CrashedBboy
// Date   : 2020-11-30

// Questions
/********************************************************************************** 

Given a non-empty array of decimal digits representing a non-negative integer, increment 
one to the integer.

The digits are stored such that the most significant digit is at the head of the list, 
and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Example 3:

Input: digits = [0]
Output: [1]

Constraints:

* 1 <= digits.length <= 100
* 0 <= digits[i] <= 9

**********************************************************************************/

// Idea
/********************************************************************************** 

use % and / to know carry, create a flag to indicate carry

**********************************************************************************/

class Solution {

private:
    bool carry = false;

public:
    vector<int> plusOne(vector<int>& digits) {
        
        if (digits.size() == 0) {
            return digits;
        }

        // do plus one
        digits[digits.size()-1] += 1;

        // check for carry
        for (int i = digits.size()-1; i >= 0; i--) {

            if (carry) { digits[i] += 1; }

            carry = digits[i]/10;
            digits[i] %= 10;
        }

        if (carry) { digits.insert(digits.begin(), 1); }

        return digits;
    }
};