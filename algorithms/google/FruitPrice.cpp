// Source : CoCubes
// Author : CrashedBboy
// Date   : 2020-05-08

// Questions
/********************************************************************************** 
[Description]

You are given a list of pairs, Each pair contains a food item and its price.

For example, ((apple, 120), (banana, 200), (apple, 150), ...).

Specific food items may occur multiple times within the list of pairs, with potentially
varying prices.

For each food item, output the lowest price, highest price, and average price (rounded
down to nearest integer) for that item. The output list should be lexicographically 
(alphabetically) sorted by name of food item.

[Input]

Test cases will be provided in the following multiline text format, using only ASCII
characters.

The first line contains one integer C, which is number of test case that will follow.
The second line is blank.
From the third line onwards, the test cases separated by blank lines will follow. 

Each test case has the following format:

N
F[1] X[1]
F[2] X[2]
...
F[N] X[N]

All tokens in a line are separated by a single space.

[Limits]
* Test case count: 1 <= C <= 20
* Line count per test case: 1 <= N <= 1000
* Food item name: F[i] is composed of one to ten lowercase English letters
* Price range: 1 <= X[i] <= 1000

[Output]

For each test case, output the result in the following format:

Case #i:

where i is the index of test case, starting from 1. Then for each food item is test case's
input list, output one line in this format:

X L H M

Where X is the food item, L is its lowest price, H is its highest price, M is its average
price. Note that the average price M should be rounded down to the nearest integer.
The output list of food items should be sorted by item name in lexicographically order.
Each item should only appear once. The test case should be in numerical order starting from 1.
Do not add any extra space at the end line of output.

[Sample Input]
3

3
banana 90
apple 100
apple 260

5
grapefruit 120
grape 200
grapefruit 150
grapefruit 150
grape 180

2
apple 100
apple 101
[Sample Output]
Case #1:
apple 100 260 180
banana 90 90 90

Case #2:
grape 180 200 190
grapefruit 120 150 140

Case #3:
apple 100 101 100
**********************************************************************************/