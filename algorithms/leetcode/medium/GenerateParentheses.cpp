// Source : https://leetcode.com/problems/generate-parentheses/
// Author : CrashedBboy
// Date   : 2020-04-17

// Questions
/********************************************************************************** 
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]

**********************************************************************************/
// [idea]
// using stack to denote whether there're elements unmatched (some opening parentheses don't have closing parenthese)
// we also need to track how many opening and closing are not used into sequence: remainedOpening & remainedClosing

// main logic:

// if remainedOpening > 0
//// if stack.size > 0
////// recusion 1: append a new opening
////// recursion 2: append a new closing
//// if stack.size == 0
////// recursion: append a new opening
// if remainedOpening == 0
//// append all remained closing into sequence


class Solution {

private:

    vector<string> results;
    int pair;

    void appendParentheses(int stackSize, string& sequence, int remainedOpening, int remainedClosing) {

        if (sequence.size() == pair * 2) {

            // remainedOpening & remainedClosing should be both 0
            results.push_back(sequence);

            return;
        }

        if (remainedOpening > 0) {

            if (stackSize > 0) {

                string clonedSequence(sequence);

                // append a new '(' to stack
                clonedSequence += "(";
                appendParentheses(stackSize + 1, clonedSequence, remainedOpening - 1, remainedClosing);
                

                // append a new ')' to stack
                // stack size will decrease 1: equal to 1. add a ')' 2. pop twice (pop one pair)
                sequence += ")";
                appendParentheses(stackSize - 1, sequence, remainedOpening, remainedClosing - 1);
            
            } else {

                // append a new '(' to stack
                sequence += "(";
                appendParentheses(stackSize + 1, sequence, remainedOpening - 1, remainedClosing);
            }
        
        } else {

            // append all remained ')' into sequence
            while (remainedClosing > 0) {

                sequence += ")";
                remainedClosing -= 1;
            }

            results.push_back(sequence);
        }
    }

public:
    vector<string> generateParenthesis(int n) {

        if (n <= 0) {
            return results;
        }

        pair = n;
        
        string sequence = "";
        int stackSize = 0;
        int remainedOpening = n;
        int remainedClosing = n;

        appendParentheses(stackSize, sequence, n, n);

        return results;
    }
};