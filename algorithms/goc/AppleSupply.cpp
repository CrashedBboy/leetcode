// Source : CoCubes
// Author : CrashedBboy
// Date   : 2020-05-09

// Questions
/********************************************************************************************* 
[Description]

"Golden Apple" is an apple supply company. They have 'M' class of apples, each class 
has 'N' number of apples (N can be different of same for each class).

They accept orders via mail for 'X' apples.

If 'X' apples ordered are less than the total number of apples present in the company, 
they accept the order.
If 'X' apples ordered are more than or equal to the number of apples present in the company 
then they deliver the total amount of apples in company minus one as the company don't want to 
empty their stock. Now, the ordered apples are adjusted against the different classes, first 
adjusted with the class having the most number of apples then the balance is adjusted against
the class with second-highest number of apples and so on.

For each M-th class of apples, print 3 integers separated by space denoting the number of apples 
available in the class, apples used from the class for that order, and remaining apples against
the class.

Note:
* If multiple classes have the same number of apples, then class entered first should be selected
to adjust.
* The total number of apples in the company will always be more than 0.
* The number of classes of apples, the number of apples in every class, and the number of apples 
ordered are always positive. If any of the value is negative, print "Invalid Input".

[Input]

Each input test case is in the following format:
* The first line contains two space-separated integers denoting the value of M (the number of classes
of apples) and X (the number of apples ordered) respectively.
* The i-th line of the following M lines contains an integer each indicating the number of apples 
available in i-th class.
* The input will be read from STDIN by the candidate.

[Limits]

0 < M, N, X < 10^7

[Output]

Each output is in the following format:

* The first line should have a string and integer separated by space. If X is less than the total number 
of apples, then print "Thanks", else if X is greater than or equal to total number of apples, then print 
"Sorry" and the number of apples they can supply.

* The i-th line of the following M lines has 3 integers separated by space denoting the number 
of apples available in i-th class, apples used from the class for that order, and remaining apples
against the class.

* The output will be matched to the candidate's output printed on the STDOUT

Example:
Input:
5 150
50
15
80
10
5

Output:
Thanks 150
50 50 0
15 15 0
80 80 0
10 5 5
5 0 5

Explanation:
The total order of 150 apples is less than the total number of apple in the company 
i.e., 50+15+80+10+5 = 160. Hence the "Thanks" note and 150 separateed by space.
150 was first adjusted against the class with the first highest number of apples 80.
The balance 150 - 80 = 70 was adjusted against the second highest class of 50 ...

[Sample Input]
4 250
80
50
70
20

[Sample Output]
Sorry 219
80 80 0
50 50 0
70 70 0
20 19 1

[Test Case Input]
4 400
60
80
70
100

[Test Case Output]
Sorry 309
60 60 0
80 80 0
70 70 0
100 99 1
*********************************************************************************************/