#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> sMap;
        unordered_map<char, int> tMap;

        for (auto& c : s) {
            sMap[c] += 1;
        }

        for (auto& c : t) {
            tMap[c] += 1;
        }
        
        if (sMap.size() != tMap.size()) {
            return false;
        }

        for (auto& p : sMap) {
            char key = p.first;
            int val = p.second;
            if (tMap[key] != val) {
                return false;
            }
        }

        return true;
    }
};

int main () {

    string s = "anagram";
    string t = "nagaram";

    Solution sol;

    bool res = sol.isAnagram(s, t);

    cout << "Is anagram? " << res << endl;

    return 0;
}