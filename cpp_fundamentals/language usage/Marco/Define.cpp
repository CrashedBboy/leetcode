#include <iostream>

#define N 10
#define ADD(a,b) a+b

using namespace std;

int main(void) {

    int a = 2;
    int b = 3;

    cout << ADD(a,b)*N << endl;

    return 0;
}


/*
Q. What is the program output?
    (1) 32
    (2) 50

A. (1) 32

    Because the expression will be expressed as:
        2+3*10
    To fix the issue, we should alwas add a bracket to the #define function:
        #define ADD(a,b) (a+b)

*/