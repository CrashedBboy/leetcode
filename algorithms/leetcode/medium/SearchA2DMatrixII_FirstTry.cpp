// [idea]
// key: find a position which can divide a part into: numbers greater than & numbers smaller than
// key: starts from top-right corner: left numbers in the row are smaller, beneath numbers in the column are larger
// iterately rule out row & column

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();

        int mIndex = 0;
        int nIndex = n - 1;

        bool found = false;

        while (mIndex < m && nIndex >= 0) {

            int currentNumber = matrix[mIndex][nIndex];

            if (currentNumber > target) {
                nIndex -= 1;
            } else if (currentNumber < target) {
                mIndex += 1;
            } else {
                found = true;
                break;
            }
        }

        return found;
    }
};