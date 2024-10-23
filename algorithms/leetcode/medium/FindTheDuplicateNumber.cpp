// Source : https://leetcode.com/problems/find-the-duplicate-number/
// Author : CrashedBboy
// Date   : 2020-04-26

// Questions
/********************************************************************************** 
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate number must exist. Assume that there is only one duplicate number, 
find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2

Example 2:

Input: [3,1,3,4,2]
Output: 3

Note:
1. You must not modify the array (assume the array is read only).
2. You must use only constant, O(1) extra space.
3. Your runtime complexity should be less than O(n2).
4. There is only one duplicate number in the array, but it could be repeated more than once.
**********************************************************************************/

// [idea]
// Floyd's tortoise and hare at cycle dectection: 2 pointers

// we can view the array as a linked list: nums[i] indicates the next of node i
// for example:
// nums = [1, 3, 2, 0]

// if we start from index 0, the visiting sequence will be:
// 1 -> 3 -> 0 

// [phase 1]: cycle dectection
// we use 2 pointers to iterate the linked list:
//// hare (fast moving): moves 2 steps each time
//// tortoise (slow moving): moves 1 step each time

// both hare and tortoise start from index 0, they will meet at a position, says 'P1Meet'

// [phase 2]: find entry of cycle
// the entry of cycle is the duplicated number, because more than one element point to it
// we still use 2 pointers to iterate:
//// pointer1: move 1 step each time, start from index 0
//// pointer2: move 1 step each time, start from position 'P1Meet'

// when pointer1 and pointer2 meet, the position is the entry

// [explanation]
// figure: https://imgur.com/a/Phb6kTe

// when tortoise meet hare in phase 1:
// [x + n(y+z) + y ] / 2 = x + y
// -----> (n-1)y + nz = x

// when pointer 1 reachs entry E (from position S),
// what are the offset of pointers w.r.t. Entry of cycle?

// pointer 1: 0 % (y+z) = 0 (it's just at the entry of cycle)
// pointer 2: (y+x) % (y+z) = [y + (n-1)y + nz] % (y+z) = 0

// so we can conculde that pointer 1 will meet pointer 2 at entry of cycle

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int hare = 0;
        int tortoise = 0;

        hare = nums[hare];
        tortoise = nums[nums[tortoise]];

        // phase 1
        while (hare != tortoise) {

            hare = nums[hare];
            tortoise = nums[nums[tortoise]];
        }

        // phase 2: use hare as pointer 1, tortoise as pointer 2
        hare = 0;
        while (hare != tortoise) {

            hare = nums[hare];
            tortoise = nums[tortoise];

            // if they meet, the position is the entry of cycle
            if (hare == tortoise) {
                break;
            }
        }
        
        return hare;
    }
};