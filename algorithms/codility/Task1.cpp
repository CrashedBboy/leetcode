/********************************************************************************
There're N trees (numbered from 0 to N-1) in a forest.
The K-th tree is located at coordinates (X[K], Y[K]).

We want to build the widest possible vertical path, such that there's no tree on it.
The path must be built somewhere between a leftmost and a rightmost tree, which means that
the width of the path cannot be infinite.

What is the width of the widest possible path that can be built?

Write a function:

    int solution(vector<int> &X, vector<int> &Y);

that, given two arrays X and Y consisting of N integers each, denoting the positions of trees,
returns the width of the widest possible path that can be built.

Examples:

1. Given X=[1, 8, 7, 3, 4, 1, 8], Y=[6, 4, 1, 8, 5, 1, 7], the function should return 3.
2. Given X=[5, 5, 5, 7, 7, 7], Y=[3, 4, 5, 1, 3, 7], the function should return 2.
3. Given X=[6, 10, 1, 4, 3], Y=[2, 5, 3, 1, 6], the function should return 4.
4. Given X=[4, 1, 5, 4], Y=[4, 5, 1, 3], the function should return 3.

Write an efficient algorithm for the following assumptions:
* N is an integer within the range [2 .. 100,000]
* each element of arrays X, Y is an integer within the range [0, 1,000,000,000]
* there are no two trees with the same coordinates
* a path of width at least 1 can always be built
********************************************************************************/
#include <algorithm>

using namespace std;

int solution(vector<int> &X, vector<int> &Y) {
    
    if (X.size() == 1) {
        return 1;
    }
    
    // sort the list of X
    sort(X.begin(), X.end());
    
    // iterate through the sorted list to find largest difference
    
    // the minimum of path width is 1
    int maxWidth = 1;
    for (int i = 1; i < X.size(); i++) {
        
        maxWidth = max(maxWidth, X[i] - X[i-1]);
    }
    
    return maxWidth;
}
