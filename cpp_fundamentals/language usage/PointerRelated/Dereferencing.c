#include "stdio.h"


int main(void) {

    char str[] = "geeksforgeeks";
    int i;
    for(i=0; str[i]; i++)
        printf("\n%c%c%c%c", str[i], *(str+i), *(i+str), i[str]);
    
    getchar();
    return 0;
}

/**

Key points:
1. declaring a C-style string with double-quoted style automatically append a null-terminator at the end.
2. Why do *(str + i), *(i + str), and i[str] all print the same value?
Because i[str] format is actually a syntactic sugar, which is equivalent to *(i + str).
And (str+i) == (i+str) arithmetically, so the deferencing results are the same.

 */