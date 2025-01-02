#include <iostream>
#include <bitset>

using namespace std;

int main () {

    // using XOR to swap 
    // XOR properties:
    // 1. a ^ a = 0.   2. a ^ 0 = a   3. a ^ b ^ a = b (note: order doesn't matter)
    int a = 125, b = 45;
    a = a ^ b; // now a is (a ^ b)
    b = a ^ b; // now b is (a ^ b) ^ b, which is equal to a
    a = a ^ b; // now a is (a ^ b) ^ a, which is equal to b
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

// Checking if a Number is Even or Odd
// Check the least significant bit (LSB)
bool isOdd(int x) {
    return (x & 1) != 0;
}

// Swapping Two Numbers Without a Temporary Variable
void swap(int& a, int&b) {
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}

// Clearing the Rightmost Set Bit
// example: 1100 becomes 1000
void clearRightMostSetBit(int& a) {
    a = a & (a-1);
}

// Counting Set Bits (Hamming Weight)
// Each time x = x & (x - 1) is executed, it removes the lowest set bit.
// Repeating this until x is zero gives the count of 1-bits.
int countSetBits(int a) {
    int count = 0;
    while (a) {
        a &= (a-1);
        count += 1;
    }
    return count;
}

// For a power of 2, only one bit is set.
// The expression x & (x - 1) will be zero if x is a power of 2 (and x is not zero).
bool isPowerOfTwo(int a) {
    return (a > 0) & ((a & (a-1)) == 0);
}

bool getNthBit(int a, int N) {
    return (a >> N) & 1;
}

void setNthBit(int& a, int N) {
    a |= (1 << N);
}

void clearNthBit(int& a, int N) {
    int mask = ~(1 << N);
    a &= mask;
}

void flipNthBit(int& a, int N) {
    int mask = (1<<N);
    a ^= mask;
}

unsigned int reverseBits(unsigned int x) {

    unsigned int res;
    for (int i = 0; i < sizeof(res)*8; i++) {

        res = res<<1 | (x&1);
        x = x >> 1;
    }
    return res;
}

void binaryPrinter(unsigned int x) {
  while (x) {
    printf("%d", (x&1));
    x = x >> 1;
  }
  printf("\n");
}