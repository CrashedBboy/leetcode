#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int candidateScore = 0;
        int candidate = NULL;

        for (auto& n : nums) {

            if (candidateScore == 0) {
                candidate = n;
            }

            candidateScore += (n == candidate) ? 1 : -1;
        }

        return candidate;
    }
};


int main () {

    vector<int> inputs = {2,2,1,1,1,2,2};

    Solution sol;
    
    cout << sol.majorityElement(inputs) << endl;

    return 0;
}