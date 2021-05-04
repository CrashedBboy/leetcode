// Source : https://leetcode.com/problems/3sum/
// Author : CrashedBboy
// Date   : 2020-05-03

// Questions
/********************************************************************************** 

Given an encoded string, return its decoded string.

The encoding rule is: k[encoded_string], where the encoded_string inside the square 
brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

You may assume that the input string is always valid; No extra white spaces, square 
brackets are well-formed, etc.

Furthermore, you may assume that the original data does not contain any digits 
and that digits are only for those repeat numbers, k. For example, 
there won't be input like 3a or 2[4].

Examples:

s = "3[a]2[bc]", return "aaabcbc".
s = "3[a2[c]]", return "accaccacc".
s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

s = "2[abc3[d]ef]5[g]gb"

**********************************************************************************/

// [idea]

// use stacks to parse the string
// stack 1: brackets matching
// stack 2: repeat times
// stack 3: repeat context

// if getting ...
// * digit => push it to "times stack"
// * opening bracket => push bracket to "bracket stack" & push a emepty string to "context stack"
// * letter
//// if "bracket stack".size > 0 => append letter to context stack's top string
//// if "brackete stack" is empty => append to output string directly
// * closing bracket => pop "bracket stack", do "repeat stack.top" x "context stack.top", get "repeated"
//// if "bracket stack".size > 0 => append "repeated" to context stack's top string
//// if "brackete stack" is empty => append "repeated" to output string directly

#include <cmath>
#include <stack>

class Solution {

private:

    // 1: digit, 2: open bracket, 3: close bracket, 4: letter
    int charClassify(char c) {

        int digitDiff = c - '0';
        if (digitDiff >= 0 && digitDiff <= 9) {
            return 1;
        }

        if (c == '[') {
            return 2;
        }

        if (c == ']') {
            return 3;
        }

        return 4;
    }

    int getRepeatTimes(string s) {

        double number = 0;
        // 123, N = 3
        for (int i = 0; i < s.size(); i++) {
            int digit = (int)(s[i] - '0');
            int power = (int)(s.size() - i - 1);
            number += digit * pow(10, power);
        }

        return (int)number;
    }

    string repeatString(string s, int times) {

        string repeated = "";
        for (int i = 0; i < times; i++) {
            repeated += s;
        }

        return repeated;
    }

public:
    string decodeString(string s) {

        stack<string> contexts;
        stack<int> repeats;
        stack<char> brackets;

        string numberString = ""; // buffer to store parsed digits
        string result = "";
        
        int charType;
        for (char c : s) {

            charType = charClassify(c);

            if (charType == 1) {

                numberString += c;
            
            } else if (charType == 2) {

                // push repeat times to stack
                repeats.push( getRepeatTimes(numberString) );
                // reset number string
                numberString = "";

                // push bracket to stack
                brackets.push(c);

                // push a new empty string to stack
                contexts.push("");
            
            } else if (charType == 4) {

                if (brackets.size() > 0) {

                    // append to stack's top string
                    string top = contexts.top();
                    contexts.pop();
                    top += c;
                    contexts.push(top);
                
                } else {

                    result += c;
                }
            
            } else if (charType == 3) {

                // pop matched bracket
                brackets.pop();

                // do repeating
                string repeated = repeatString(contexts.top(), repeats.top());

                // pop repeat times and repeated string
                contexts.pop();
                repeats.pop();

                if (brackets.size() > 0) {

                    // append repeated to stack's top string
                    string top = contexts.top();
                    contexts.pop();
                    top += repeated;
                    contexts.push(top);

                } else {

                    result += repeated;
                }
            }
        }

        return result;
    }
};