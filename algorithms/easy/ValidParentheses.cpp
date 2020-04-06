// Source : https://leetcode.com/problems/valid-parentheses/
// Author : CrashedBboy
// Date   : 2020-04-06

// Questions
/********************************************************************************** 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true
Example 2:

Input: "()[]{}"
Output: true
Example 3:

Input: "(]"
Output: false
Example 4:

Input: "([)]"
Output: false
Example 5:

Input: "{[]}"
Output: true

**********************************************************************************/

// [idea]
// use stack's property

// iterate the string
//// if the current iterated is "for opening" => push into stack
//// if the current iterated is "for closing" => check whether it is matched with stack's top
////// if matched => pop the stack's top

// after the iteration, if there're some remains in stack, return false

// definition of 'match':
//// current iterated parenthesis is "for closing"
////// & it's the same type as stack's top
////// & top of stack is "for opening"

class Solution {

private:
    stack<char> parentheses;

    bool isForClosing(char p) {

        if (p == ')' || p == '}' || p == ']') {

            return true;
        }

        // means the char is for opening
        return false;
    }

    bool isMatched(char opening, char closing) {

        if ( (opening == '(' && closing == ')')
            || (opening == '[' && closing == ']')
            || (opening == '{' && closing == '}') ) {

            return true;
        }

        return false;
    }


public:
    bool isValid(string s) {
        
        int size = s.size();

        if (size == 0) {
            return true;
        }

        for (int i = 0; i < size; i++) {

            char c = s[i];

            if (isForClosing(c)) {

                // c is ')', ']' or '}'

                if (parentheses.size() == 0) {
                    return false;
                }

                if (! isMatched(parentheses.top(), c)) {
                    return false;
                
                } else {

                    // they are matched

                    parentheses.pop();
                }

            } else {

                parentheses.push(c);
            }
        }

        // check if there're remains in stack
        if (parentheses.size() == 0) {

            return true;

        } else {

            return false;
        }
    }
};