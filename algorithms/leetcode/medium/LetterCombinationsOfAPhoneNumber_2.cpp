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

// iterative way

#include <unordered_map>
#include <string>
#include <cmath>
#include <utility>

using namespace std;

class Solution {

private:

    vector<string> digit_map;

    vector<string> answers;

public:
    vector<string> letterCombinations(string digits) {

        if (digits.size() == 0) {
            return vector<string>(0);
        }

        // initial digit_map
        digit_map = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        answers = {""}; // initial seed

        for (int i = 0; i < digits.size(); i++) {

            int num = digits[i] - '0'; // convert from char to int

            vector<string> tmpAnswers;
            for (int j = 0; j < answers.size(); j++) {
                for (int k = 0; k < digit_map[num].size(); k++) {

                    tmpAnswers.push_back(answers[j] + digit_map[num][k]);
                }
            }

            answers.swap(tmpAnswers);
        }

        return answers;
    }
};