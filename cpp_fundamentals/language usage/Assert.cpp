#include <cassert>
#include <iostream>

using namespace std;


int main(void) {

    int* ptr = (int*)malloc(sizeof(int) * 2500000000);
    assert(ptr);
    free(ptr);

    int i = 12;

    assert(i==11);

    return 0;
}