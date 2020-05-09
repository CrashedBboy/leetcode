// Source : CoCubes
// Author : CrashedBboy
// Date   : 2020-05-09

// Questions
/********************************************************************************** 
[Description]
You are given an aerial map of an area in the form of a 2D integer matrix named grid. 
The area is divided into different sections which are owned by respective owners.

Each owner is assigned to a unique number and the sections owned by them are denoted 
by that number in the grid.

Sections in the grid are divided as follows:
* All adjacent cells having the same number in the grid form a single section. Adjacent 
cells are immediate top, left, bottom, and right cells.
* If two adjacent cells in the grid have a different number, then they are part of 
different sections.
* If two cells having the same number are diagonal to each other then they are also
considered as different sections.

In summer after a severe drought, there is a heavy shortage of water. You have to find 
the largest section in the grid which can be filled to store maximum water.
To fill the water you have to replace the elements of the largest section in the grid 
with -1. Print the updated grid.

Note:
* Only one section in the grid will have a maximum area.
* A single cell having no adjacent with same number, it is considered as a separate 
section.
* Water can be filled in only one section of the grid.
* The grid will not be empty.

[Input]
The input consists of two lines:
* The first line consistes of two space-separated integers the first integer represents 
the rows of the grid and the second integer represents the columns of the grid.
* The second line consists of all the elements of the grid separated by spaces.

[Output]
The elements of the updated grid in a single line separated by spaces.

[Constraints]
* 0 < The number of rows of the grid <= 1000
* 0 < The number of columns of the grid <= 1000
* 0 < The value of each element in the grid < 10^9

Example:
Input:
4 5
1 1 1 1 1 12 2 2 3 1 1 2 3 3 1 2 1 3 1

Output:
-1 -1 -1 -1 -1 -1 2 2 2 3 -1 -1 2 3 3 01 2 1 3 1
Explanation:
The grid formed by the given input is:
1 1 1 1 1
1 2 2 2 3
1 1 2 3 3
1 1 2 3 3 
1 2 1 3 1
The largest section in the grid is the land owned by owner 1 with 0 blocks, the other 2 
sections owned by owner 1 are separated from the largest section hence not considered 
for filling water.
So, after filling the largest section of the grid it becomes:
-1 -1 -1 -1 -1
-1  2  2  2  3
-1 -1  2  3  3
-1  2  1  3  1

[Sample Input]
2 2
1 1 1 1

[Sample Output]
-1 -1 -1 -1

**********************************************************************************/