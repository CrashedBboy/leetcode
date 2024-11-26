#include <iostream>
#include <cstdio>

using namespace std;


void sizeOfArray() {

    int arr1[5] = {2, 3, 4, 5, 6};
    cout << "size of arr1: " << (sizeof(arr1)/sizeof(arr1[0])) << endl; // 5

    int* arr2 = (int*)malloc(sizeof(int) * 5);
    cout << "size of arr2 != " << (sizeof(arr2)/sizeof(arr2[0])) << endl; // 2 (sizeof(arr2) returns the size of 'pointer'!, which is 8 bytes in 64-bit machines)

    free(arr2);
}

// Big-endian stores the most significant byte of a number at the lowest memory address
// while little-endian stores the least significant byte at the lowest memory address. 
void arrayCast() {
    int* arr = (int*)malloc(sizeof(int) * 2);
    *(arr) = 0x12345678;
    *(arr+1) = 0x11223344;
    cout << "arr:" << endl;
    for (int i = 0; i < 2; i++) {
        cout << showbase << hex << *(arr+i) << endl;
    }

    char* carr = (char*)arr;
    cout << "carr:" << endl;
    for (int i = 0; i < 2*4; i++) {
        printf("*(carr+%d) = %x\n", i, *(carr+i));
        // cout << showbase << hex << *(carr+i) << endl;
    }
    free(arr);
}

int main (void) {
    sizeOfArray();
    arrayCast();

    return 0;
}


/*
Output:

size of arr1: 5
size of arr2 != 2
arr:
0x12345678
0x11223344
carr:
*(carr+0) = 78
*(carr+1) = 56
*(carr+2) = 34
*(carr+3) = 12
*(carr+4) = 44
*(carr+5) = 33
*(carr+6) = 22
*(carr+7) = 11

*/