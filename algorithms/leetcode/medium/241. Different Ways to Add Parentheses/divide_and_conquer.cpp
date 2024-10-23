#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isOperand(char& c) {

    if (c == '+' || c == '-' || c == '*') {
        return false;
    }
    return true;
}

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {

        vector<int> numbers;
        bool isSingle = true;

        for (int i = 0; i < expression.size(); i++) {

            if ( !isOperand(expression[i]) && i != 0) {
                isSingle = false;
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1, expression.size() - i - 1));

                for (auto& l : left) {
                    for (auto& r : right) {
                        switch (expression[i]) {
                            case '+':
                                numbers.push_back(l + r);
                                break;
                            case '-':
                                numbers.push_back(l - r);
                                break;
                            case '*':
                                numbers.push_back(l * r);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }

        if (isSingle) {
            numbers.push_back(stoi(expression));
        }

        return numbers;
    }
};