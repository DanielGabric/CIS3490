Q4.c

DESCRIPTION: Take the sequence then perform
longest common subsequence on it and its reverse
and you will get the longest palindrome.

INPUT:
ACGACAACGGTAGCAGACGATGACATACGA
OUTPUT:
AGCAACGTAGCAGACGATGCAACGA
25

INPUT:
ACGCAGTAACCGCTCAATGCAGC
OUTPUT:
CGCGTAACCGCCAATGCGC
19

INPUT:
TCTATAGTCTACCTCACAGTCGATTTT
OUTPUT:
TTTAGCTACCTCCATCGATTT
21


Q5.c

DESCRIPTION: Backtracking with constraint programming,
use val/9 as the row and val mod 9 as the column,
so you just increment val and stop when it is 81.
Optimized by using row/col/square constraints and
iteratively skip over "filled in" squares.

INPUT:
4 2 6 0 0 0 0 0 0
0 1 0 9 8 0 0 0 0
0 0 0 0 1 0 0 6 0
0 0 5 0 0 0 0 0 1
0 6 0 4 0 5 0 8 0
9 0 0 0 0 0 3 0 0 
0 7 0 0 6 0 0 0 0
0 0 0 0 3 2 6 1 0
0 0 0 0 0 0 9 2 5
OUTPUT:
4 2 6 3 5 7 1 9 8 
7 1 3 9 8 6 5 4 2 
8 5 9 2 1 4 7 6 3 
2 8 5 6 9 3 4 7 1 
3 6 1 4 7 5 2 8 9 
9 4 7 1 2 8 3 5 6 
1 7 2 5 6 9 8 3 4 
5 9 4 8 3 2 6 1 7 
6 3 8 7 4 1 9 2 5 