/*

Given N fractions, numbered from 0 to N-1.
Your task is to count the number of occurrences of the fraction that appears most often.

NOTE: two fractions may be equal even though they're in different form. e.g. 3/5 = 6/10

The params are two arrays X and Y consisting of N int each (which represent the K-th fraction as X[K]/Y[K])
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <string>

using namespace std;

int gcd(int a, int b) {
    int r = 1;
    while (r != 0) {
        r = a%b;
        a = b;
        b = r;
    }

    return a;
}

int solution(vector<int> &X, vector<int> &Y) {

    int max_count = 0;
    unordered_map<string, int> counts;
    
    int i = 0; // idx
    while (i < X.size()) {

        int x = X[i]; int y = Y[i];

        // find the greatest common divisor of X & Y
        int xy_gcd = gcd(x, y);

        // divide both X and Y by the gcd
        x /= xy_gcd; y /= xy_gcd;

        // utilize hash table to record the frequency
        string key = to_string(x) + "," + to_string(y);
        counts[key] += 1;

        // update the max occurrence
        if (counts[key] > max_count) {
            max_count = counts[key];
        }

        i += 1;
    }

    return max_count;
}
