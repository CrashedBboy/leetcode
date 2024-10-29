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

/*
Scenarios of using Union:

1. Memory Optimization:
When you have variables that are mutually exclusive in usage,
such as in embedded systems, using a union saves memory by overlapping storage for different variables.

2. Interpreting Data in Multiple Ways:
Unions are useful for reading data in different formats,
such as interpreting bytes from hardware registers 
or network packets where the same memory location may need to be interpreted as different data types.
*/