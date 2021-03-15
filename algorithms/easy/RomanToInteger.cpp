// [idea]: 
// create a hash map to store the mapping between symbol and its values
// then, read the string from the right to the left
// key logic: if s[i+1] > s[i] --> subtract the cumulative sum by s[i+1]; else: add s[i+1]

#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {

        int sum = 0;

        if (s.size() >= 1) {
            sum += romanDigitValueMap[s[s.size()-1]];
        }

        for (int i = s.size() - 2; i >= 0; i--) {

            int currVal = romanDigitValueMap[s[i]];
            int prevVal = romanDigitValueMap[s[i+1]];

            if (currVal >= prevVal) {
                sum += currVal;
            }
            else {
                sum -= currVal;
            }
        }

        return sum;
    }

private:
    unordered_map<char, int> romanDigitValueMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
    };
};


int main () {

    string s = "MCMXCIV";
    // string s = "IX";
    // string s = "LVIII";

    Solution sol;
    cout << sol.romanToInt(s) << endl;

    return 0;
}