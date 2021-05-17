#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {

        unordered_map<char, char> closeSymbol;
        closeSymbol['('] = ')';
        closeSymbol['{'] = '}';
        closeSymbol['['] = ']';

        stack<char> charStack;

        for (auto& c : s) {
            if (charStack.empty()) {
                charStack.push(c);
            }
            else {
                if (c == '(' || c == '[' || c == '{') {
                    charStack.push(c);
                }
                else {
                    if (closeSymbol[charStack.top()] != c) {
                        return false;
                    }
                    else {
                        charStack.pop();
                    }
                }
            }
        }

        return charStack.empty();
    }
};