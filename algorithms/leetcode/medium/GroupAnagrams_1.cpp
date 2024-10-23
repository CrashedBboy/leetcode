// Source : https://leetcode.com/problems/group-anagrams/
// Author : CrashedBboy
// Date   : 2020-04-22

// Questions
/********************************************************************************** 
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Note:
* All inputs will be in lowercase.
* The order of your output does not matter.

**********************************************************************************/

// [idea]
// sort the word then compare if identical

class Solution {

private:

    static bool charCmp(char c1, char c2) {
        return c1 < c2;
    }

public:

    vector<vector<string>> groupAnagrams(vector<string>& strs){

        vector<vector<string>> results;

        if (strs.empty()) {

            return results;
        }

        // sort every word
        vector<string> sortedStrings;
        for (int i = 0; i < strs.size(); i++) {

            string newString(strs[i]);

            sort(newString.begin(), newString.end(), charCmp);
            sortedStrings.push_back(newString);
        }

        // use hash table to store 
        unordered_map<string, vector<string>> groups;

        for (int i = 0; i < sortedStrings.size(); i++) {
            groups[sortedStrings[i]].push_back(strs[i]);
        }

        // move lists from hast table to output list
        for (auto p : groups) {
            results.push_back(p.second);
        }

        return results;
    }
};