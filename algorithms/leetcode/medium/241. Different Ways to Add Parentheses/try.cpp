#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        vector<int> numbers;
        bool isSingle = true;

        for (int i = 0; i < expression.size(); i++) {

            if ( isOperand(expression[i]) && i != 0) {
                isSingle = false;
                // left results = divide and conquer
                // right results = divide and conquer

                // switch the operator, calculate : left (op) right
                // and push to vect
            }
        }

        if (isSingle) {
            // convert this whole expression into number,
            // push it into vect, 
        }
    }
};

bool isOperand(char& c) {

    if (c == '+' || c == '-' || c == '*') {
        return false;
    }
    return true;
}