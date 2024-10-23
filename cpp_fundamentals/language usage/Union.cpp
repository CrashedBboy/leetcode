#include <stdio.h>

using namespace std;

union data {
    char c;
    int num;
};

int main() {

    union data a;

    a.num = 0x12345678;

    printf("c: %x\n", a.c); // 0x78 (if little endian)

    // if little endian:
    // lower value put on lower address
    // union members aligned on low address

	return 0;
}