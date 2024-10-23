#include <string>
#include <iostream>
#include <stack>

using namespace std;

// 0 -> A
// 1 -> B
// 25 -> Z
// 26 -> BA
// 27 -> BB


class Solution {

    public:

        string toBaseTwentySix(int decimal) {

            int BASE = 26;
            char STARTING_LETTER = 'A';

            stack<char> digits;

            while (decimal > 0) {
                char letter = STARTING_LETTER + (decimal%26);

                digits.push(letter);

                decimal = decimal / BASE;
            }

            string answer = "";

            while (!digits.empty()) {
                char d = digits.top();
                answer += d;

                digits.pop();
            }

            return answer;
        }
};


int main () {

    int input = 27;

    Solution sol;

    cout << sol.toBaseTwentySix(input) << endl;

    return 0;
}