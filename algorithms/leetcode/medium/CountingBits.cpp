// Source : https://leetcode.com/problems/counting-bits/
// Author : CrashedBboy
// Date   : 2020-04-08

// Questions
/********************************************************************************** 
Given a non negative integer number num.
For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]

Follow up:
It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
**********************************************************************************/

// [idea]
// use bit shifting

// define:
// ones[0] = 0
// ones[1] = 1

// bottom-up solution:

// how many ones in binary representation of "3" (0b11)
// 3 & 1 == (0b11) & (0b01) == 1
// ones[ 3 >> 1] = ones [0b11 >> 1] = ones[0b1] = 1
// ones[3] = (3&1) + ones[6 >> 1]

// how many ones in binary representation of "6" (0b110)
// 6 & 1 == 0 ----> right most bit in sequence "110" is zero
// ones[6 >> 1] = ones[3] = 2 ---> 0b110 >> 1 == 0b11 (3 in decimal), which has two ones
// ones[6] = (6 & 1) + ones[6 >> 1]



class Solution {
public:
    vector<int> countBits(int num) {

        // the vector used to store counted bits for every number
        vector<int> ones;

        // check input
        ones.push_back(0);
        if (num == 0) {
            return ones;
        }

        ones.push_back(1);
        if (num == 1) {
            return ones;
        }

        // now the vector 'ones' is initialized, ones = {0, 1}

        // expand the size of vector to 'num'
        for (int n = 2; n <= num; n++) {
            ones.push_back(0);
        }

        for (int n = 2; n <= num; n++) {

            ones[n] = (n & 1) + ones[n >> 1];
        }

        return ones;
    }
};