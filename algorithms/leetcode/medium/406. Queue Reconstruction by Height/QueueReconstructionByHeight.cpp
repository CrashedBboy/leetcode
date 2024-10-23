#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// sort by height then order
bool custom_cmp (const vector<int>& a, const vector<int>& b) {

    if (a[0] != b[0]) {
        return (a[0] > b[0]);
    }
    else {
        return (a[1] < b[1]);
    }
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        
        // idea
        // sort by height then order, ans insert to queue


        sort(people.begin(), people.end(), custom_cmp);

        vector<vector<int>> ans;

        for (auto& p : people) {
            int height = p[0];
            int greater = p[1];
            int greater_count = 0;

            int i = 0;
            for (; i < ans.size(); i++) {

                if (ans[i][0] >= height) {
                    if (greater_count < greater) {
                        greater_count += 1;
                    }
                    else if (greater_count == greater) {
                        break;
                    }
                }
            }

            ans.insert(ans.begin() + i, p);
        }

        return ans;
    }
};