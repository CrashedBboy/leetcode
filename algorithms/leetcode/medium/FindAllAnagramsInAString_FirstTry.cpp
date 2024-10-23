#include <string>
#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        // create hash table to store frequence of target string (p)
        unordered_map<char, int> targetFreq;

        for (auto& c : p) {
            targetFreq[c] += 1;
        }

        // create hash table to store freq of sliding window string
        unordered_map<char, int> windowFreq;

        vector<int> answers;

        if (p.size() > s.size()) {
            return answers;
        }

        for (int i = 0; i < s.size() - (p.size() - 1); i++) {

            // reset
            for (auto& p : targetFreq) {
                char key = p.first;
                windowFreq[key] = 0;
            }
            bool stop = false;

            for (int j = 0; j < p.size(); j++) {
                char current = s[i + j];

                if (targetFreq.count(current) == 0) {
                    stop = true;
                    break;
                }
                else {
                    windowFreq[current] += 1;
                    if (windowFreq[current] > targetFreq[current]) {
                        stop = true;
                        break;
                    }
                }
            }

            if (stop) {
                continue;
            }
            else {

                // compare whether targetFreq & windowFreq are identical
                bool allIdentical = true;
                for (auto& p : targetFreq) {
                    char key = p.first;
                    int freq = p.second;

                    if (windowFreq[key] != freq) {
                        allIdentical = false;
                        break;
                    }
                }

                if (allIdentical) {
                    answers.push_back(i);
                }
            }
        }

        return answers;
    }
};


int main() {

    string s = "cbaebabacd";
    string p = "abc";

    Solution sol;

    vector<int> answers = sol.findAnagrams(s, p);

    for (auto& idx : answers) {
        cout << idx << ",";
    }


    return 0;
}