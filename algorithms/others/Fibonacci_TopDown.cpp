#include <iostream>
#include <vector>

using namespace std;

int fibonacci (int n, vector<int>& dp) {

    if (n <= 0) { return 0; }

    if (dp[n] != -1) {
        return dp[n];
    }
    else {

        if (n == 1 || n == 2) {
            dp[n] = 1;
            return 1;
        }
        else {
            int ans = fibonacci(n - 1, dp) + fibonacci(n - 2, dp);
            dp[n] = ans;
            return ans;
        }
    }
}

int main () {

    vector<int> dp (21, -1);

    for (int i = 1; i <= 20; i++) {
        cout << fibonacci(i, dp) << " ";
    }
    cout << endl;

    return 0;
}