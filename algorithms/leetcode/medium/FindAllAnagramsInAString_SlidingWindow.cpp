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

        vector<int> answers;

        int matchedCount = 0;

        int begin = 0, end = 0;
        while (end < s.size()) {

            
            targetFreq[s[end]] -= 1;
            if (targetFreq[s[end]] >= 0) {
                matchedCount += 1;
            }

            cout << begin << "->" << end << ", count: " << matchedCount << endl;

            if ((end-begin+1) == p.size()) {

                if (matchedCount == p.size()) {
                    answers.push_back(begin);
                }

                // move both begin and end
                targetFreq[s[begin]] += 1; // reset
                if (targetFreq[s[begin]] > 0) {
                    matchedCount -= 1;
                }
                begin += 1;
                end += 1;
            } else {
                // move end forward only
                end += 1; 
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