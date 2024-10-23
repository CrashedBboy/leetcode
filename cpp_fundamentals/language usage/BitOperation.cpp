#include <iostream>
#include <bitset>

using namespace std;

int main () {

    int a = 125, b = 45;

    // using XOR to swap 
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << "a: " << a << ", b: " << b << endl;

    // set n-th bit to 1 using OR
    int c = 0b01001;
    int d = c | (1<<2);

    cout << "c: " << bitset<8>(c) << ", d: " << bitset<8>(d) << endl;

    // clear n-th bit: using AND with 0

    // reverse n-th bit: using XOR with 1

    // shift
    int e = 0b11010110;
    for (int i = 0; i < 8; i++) {
        e = (e>>1);
        cout << bitset<8>(e) << endl; 
    }

    return 0;
}