// Source : https://leetcode.com/problems/palindromic-substrings/
// Author : CrashedBboy
// Date   : 2020-04-18

// Questions
/********************************************************************************** 
Given a string, your task is to count how many palindromic substrings in this string.
The substrings with different start indexes or end indexes are counted as different 
substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 

Note: The input string length won't exceed 1000.

**********************************************************************************/

class Solution {
public:
    int countSubstrings(string s) {
        
        int palindromicCount = 0;

        if (s.empty()) {
            return palindromicCount;
        }

        // iterate through each element, use the element as center to check palindrome
        for (int center = 0; center < s.size(); center++) {

            // odd length of substring
            // lstart and rstart are the same (at center)
            for (int lPtr = center, rPtr = center; (lPtr >= 0) && (rPtr < s.size()); lPtr--, rPtr++) {

                if (s[lPtr] == s[rPtr]) {

                    palindromicCount += 1;

                } else {

                    break;
                }
            }

            // even length of substring
            // lstart = center, rstart = center+1
            for (int lPtr = center, rPtr = center+1; (lPtr >= 0) && (rPtr < s.size()); lPtr--, rPtr++) {

                if (s[lPtr] == s[rPtr]) {

                    palindromicCount += 1;

                } else {

                    break;
                }
            }
        }

        return palindromicCount;
    }
};