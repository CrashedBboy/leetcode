#include "stdlib.h"
#include "stdio.h"

int main()
{
	char a[2][3][3] = {'g','e','e','k','s','f','o',
						'r','g','e','e','k','s'};
	printf("%s ", **a);
	getchar();
	return 0;
}

/**
Program output:

	"geeksforgeeks"

 */

/**
Hints and explanation:

a[0,0,0], a[0,0,1], a[0,0,2], a[0,1,0], a[0,1,1], a[0,1,2], a[0,2,0], a[0,2,1], a[0,2,2], ...

1. Assigning a one-dimensional initializer to a 3D array, why it can work?
although the matrix is conceptually 3-dimensional, but it lays linearly in memory.
so the item next to the a[0][0][2] would be a[0][1][0], and so on..

2. Why printing **a can print all the matrix?

a -> points to address of the whole matrix(2,3,3)
*a -> points to addr of the first matrix(3,3)
**a -> points to addr of the first array (3)

print("%s") expects an address of null-terminated string, the the printing will terminates once encountering a '\0'.
So that's why it prints beyond the array of size 3.

Also, the initializer adds '\0' to the unspecified items in the matrix.
 */