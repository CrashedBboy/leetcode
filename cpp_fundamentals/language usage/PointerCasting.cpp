// understand...
// 1. casting different types of pointer
// 2. big endian vs. little endian

#include <stdio.h>

using namespace std;

int main() {

    int number = 0x12345678;
    int* intPtr = &number;
    printf("*intPtr = %x, intPtr = %x \n", *intPtr, intPtr);

    char* charPtr = (char*)intPtr;
    for (int offset = 0; offset < sizeof(int); offset++) {
        printf("*(charPtr+%d) = %x, charPtr+%d = %x \n", offset, *(charPtr+offset), offset, charPtr+offset);
    }
        
    // if CPU is little-endian, the output would be:
    // *intPtr = 12345678, intPtr = 8d71f564
    // *(charPtr+0) = 78, charPtr+0 = 8d71f564
    // *(charPtr+1) = 56, charPtr+1 = 8d71f565
    // *(charPtr+2) = 34, charPtr+2 = 8d71f566
    // *(charPtr+3) = 12, charPtr+3 = 8d71f567

	return 0;
}