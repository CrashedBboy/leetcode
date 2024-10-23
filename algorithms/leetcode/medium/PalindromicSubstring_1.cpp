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

        // every element itself is a palindromic substring
        palindromicCount += s.size();

        if (s.size() >= 2) {

            // iterate through all possible substring length: 2, 3, .. , N
            for (int length = 2; length <= s.size(); length++) {

                // iterate through all start position of substring
                for (int start = 0; start <= (s.size()-length); start ++) {

                    // use two pointer to iterate to opposite from center position

                    int lstart;
                    int rstart;
                    if (length%2 == 0) {
                        // even
                        rstart = start + length/2;
                        lstart = rstart - 1;
                    } else {
                        // odd
                        lstart = start + (length-1)/2 - 1;
                        rstart = lstart + 2;
                    }

                    bool identical = true;
                    for (int i = 0; i <= (lstart - start); i++) {

                        if (s[lstart - i] != s[rstart + i]) {
                            identical = false;
                            break;
                        }
                    }

                    if (identical) {
                        palindromicCount += 1;
                    }
                }
            }
        }

        return palindromicCount;
    }
};