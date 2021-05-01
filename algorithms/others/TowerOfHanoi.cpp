#include <iostream>
#include <string>

using namespace std;

// let's say the three tower can be view as source, destination, tmp
// to move all plates from source to destination:
// 1. move top n-1 plates from source to tmp
// 2. move the bottom plates from source to destination
// 3. move the n-1 plates destination

class Solution {

    public:

        /**
         * @param n: number of plate
        */
        void TowerOfHanoi(int n, string source, string destination, string tmp) {

            if (n == 1) {
                cout << "Move a plate from " << source << " to " << destination << endl;
            }
            else {
                TowerOfHanoi(n-1, source, tmp, destination); // move top (n-1)th plates from source to tmp
                TowerOfHanoi(1, source, destination, tmp); // move the bottom plates from source to destination
                TowerOfHanoi(n-1, tmp, destination, source); // move back: move the top (n-1)-th plates from tmp to destination
            }
        }
};


int main() {

    Solution sol;
    
    int plateNumber = 3;
    string tower1 = "A";
    string tower2 = "B";
    string tower3 = "c";

    sol.TowerOfHanoi(plateNumber, tower1, tower2, tower3);

    return 0;
}