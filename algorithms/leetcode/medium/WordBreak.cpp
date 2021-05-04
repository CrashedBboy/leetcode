#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp (s.size()+1, false);
        dp[0] = true;

        for (int end = 0; end < s.size(); end++) {
            for (int start = 0; start <= end; start++) {
                if (dp[start] == true) {
                    // check s[start+1:end] exists in wordDict or not
                    string subSequence (s, start, (end-start+1));
                    if (wordExist(subSequence, wordDict)) {
                        dp[end+1] = true;
                        break;
                    }
                }
            }
        }

        return dp[s.size()];
    }

private:
    bool wordExist(string s, vector<string>& wordDict) {

        bool exist = false;
        for (auto& word : wordDict) {
            if (s == word) {
                exist = true;
                break;
            }
        }

        return exist;
    }
};



int main () {

    // string s = "leetcode";
    string s = "catsandog";
    // vector<string> wordDict = {"leet", "code"};
    vector<string> wordDict = {"cats","dog","sand","and","cat"};

    Solution sol;

    bool result = sol.wordBreak(s, wordDict);

    cout << result << endl;
    return 0;
}