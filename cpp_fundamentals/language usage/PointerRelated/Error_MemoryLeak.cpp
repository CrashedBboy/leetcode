#include <iostream>

using namespace std;

void problem() {

    int* array = new int[200];

    // NO "delete [] array;"
}

void solution() {
    // alternative: use smart pointer

    int* array = new int[200];
    delete [] array;
}

int main(void) {

    for (int i = 0; i < 20; i++) {
        // problem();
        solution();
    }

    return 0;
}

// COMMAND OF valgrind: valgrind --leak-check=yes ./exec

/*
==3543== Memcheck, a memory error detector
==3543== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==3543== Using Valgrind-3.18.1 and LibVEX; rerun with -h for copyright info
==3543== Command: ./exec
==3543==
==3543==
==3543== HEAP SUMMARY:
==3543==     in use at exit: 16,000 bytes in 20 blocks
==3543==   total heap usage: 21 allocs, 1 frees, 88,704 bytes allocated
==3543==
==3543== 16,000 bytes in 20 blocks are definitely lost in loss record 1 of 1
==3543==    at 0x484A2F3: operator new[](unsigned long) (in /usr/libexec/valgrind/vgpreload_memcheck-amd64-linux.so)
==3543==    by 0x10919E: problem() (Error_MemoryLeak.cpp:7)
==3543==    by 0x1091BF: main (Error_MemoryLeak.cpp:15)
==3543==
==3543== LEAK SUMMARY:
==3543==    definitely lost: 16,000 bytes in 20 blocks
==3543==    indirectly lost: 0 bytes in 0 blocks
==3543==      possibly lost: 0 bytes in 0 blocks
==3543==    still reachable: 0 bytes in 0 blocks
==3543==         suppressed: 0 bytes in 0 blocks
==3543==
==3543== For lists of detected and suppressed errors, rerun with: -s
==3543== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
 */