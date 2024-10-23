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
// count letter frequency for every string, then embed frequency to a string (to be key of hash table)

class Solution {

private:

    string frequencyEmbedding(vector<int> frequency) {

        string embedded;

        for (int i = 0; i < frequency.size(); i++) {
            embedded += "#" + std::to_string(frequency[i]);
        }

        return embedded;
    }

public:

    vector<vector<string>> groupAnagrams(vector<string>& strs){

        vector<vector<string>> results;

        if (strs.empty()) {

            return results;
        }
        
        unordered_map<string, vector<int>> groups;
        for (int i = 0; i < strs.size(); i++) {

            string anagram = strs[i];
            vector<int> letterFrequency(26, 0);
            for (int j = 0; j < anagram.size(); j++) {

                letterFrequency[(int)(anagram[j] - 'a')] += 1;
            }

            string embedded = frequencyEmbedding(letterFrequency);

            groups[embedded].push_back(i);
        }

        for (auto p : groups) {

            vector<string> group;
            for (int i = 0; i < p.second.size(); i++) {
                group.push_back(strs[p.second[i]]);
            }
            results.push_back(group);
        }

        return results;
    }
};