#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        
        if (n <= 1) {
            return 0;
        }

        vector<int> primes;
        for (int i = 2; i <= n; i++) {

            bool isPrime = true;
            for (auto& p : primes) {
                if (p > (i/2)) {
                    break;
                }
                if (i%p == 0) {
                    isPrime = false;
                    break;
                }
            }

            if (isPrime) {
                primes.push_back(i);
            }
        }

        return primes.size();
    }
};


int main () {

    int input = 10;

    Solution sol;

    cout << sol.countPrimes(input) << endl;

    return 0;
}