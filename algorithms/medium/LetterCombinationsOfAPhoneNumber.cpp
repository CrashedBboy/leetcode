// Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Author : CrashedBboy
// Date   : 2020-11-29

// Questions
/********************************************************************************** 

Given a string containing digits from 2-9 inclusive, return all possible letter 
combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.

[digit mapping]:
https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]

Constraints:

* 0 <= digits.length <= 4
* digits[i] is a digit in the range ['2', '9'].

************************************************************************************/

// Idea:

// max combination number = 4^4 = 256
// backtracking: using recursion to find all combinations, then push to answer vectors

#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

class Solution {

private:

    vector<string> digit_map;

    vector<string> answer;
    int answerIndicator = -1;

    void compute(string& digits, int currentIndex, string currentCombined) {

        if (currentIndex == digits.size()) {
            answerIndicator += 1;
            answer[answerIndicator] = currentCombined;
            return;
        }
        
        int d = digits[currentIndex] - '0';

        for (int i = 0; i < digit_map[d].size(); i++) {
            compute(digits, (currentIndex+1), currentCombined+digit_map[d][i]);
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        
        if (digits.size() == 0) {
            return vector<string>(0);
        }

        int maxCombinations = pow(4, digits.size());
        answer = vector<string>(maxCombinations);

        digit_map = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        compute(digits, 0, "");

        if (answerIndicator < (maxCombinations - 1)) {
            answer.erase(answer.begin() + answerIndicator + 1, answer.end());
        }
        
        return answer;
    }
};