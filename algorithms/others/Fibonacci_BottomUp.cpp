#include <vector>
#include <iostream>

using namespace std;

int main () {

    int N = 20;

    vector<int> dp (N+1, 0);

    dp[1] = 1; dp[2] = 1;
    for (int i = 3; i <= N; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    for (int i = 1; i <= N; i++) {
        cout << dp[i] << ",";
    }
    cout << endl;

    return 0;
}