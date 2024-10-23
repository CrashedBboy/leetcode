#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string lcp = "";

        if (strs.size() == 0) {
            return lcp;
        }

        int idx = 0;

        while (true) {

            char target;
            if (idx < strs[0].size()) {
                target = strs[0][idx];
            }
            else {
                return lcp;
            }

            for (int i = 1; i < strs.size(); i++) {
                if (idx >= strs[i].size() || strs[i][idx] != target) {
                    return lcp;
                }
            }

            lcp += target;
            idx += 1;
        }

        return lcp;
    }
};



int main () {

    vector<string> inputs = {"flower","flow","flight"};

    Solution sol;

    string lcp = sol.longestCommonPrefix(inputs);

    cout << lcp << endl;

    return 0;
}