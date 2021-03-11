#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        
        vector<string> answers;

        for (int i = 1; i <= n; i++) {

            string s = "";
            if (i%3 == 0) {
                s += "Fizz";
            }
            
            if (i%5 == 0) {
                s += "Buzz";
            }
            
            if (i%3 && i%5) {
                s = to_string(i);
            }

            answers.push_back(s);
        }

        return answers;
    }
};

int main () {

    int n = 15;

    Solution s;

    vector<string> answers = s.fizzBuzz(n);

    for (auto& str : answers) {
        cout << str << "," << endl;
    }

    return 0;
}