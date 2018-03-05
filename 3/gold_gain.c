// Test main doesn't work with syntax of gold_gain parameter. Oh well

#define MAX(a, b, c) (a > b && a > c ? a : b > c ? b : c)

int gold_gain(int** mine, int n) {
    int max = 0;
    for (int col = 1; col < n; col++) {
        for (int row = 0; row < n; row++) {
            int a = 0, b = 0, c = 0;
            if (row > 0)
                a = mine[row - 1][col - 1];
            b = mine[row][col - 1];
            if (row < n - 1)
                c = mine[row + 1][col - 1];
            mine[row][col] += MAX(a, b, c);
            if (col == n - 1) {
                if (max < mine[row][col])
                    max = mine[row][col];
            }
        }
    }
    return max;
}

#include <stdio.h>
int main() {

    int a[3][3] = {
        { 1, 0, 0 },
        { 0, 3, 4 },
        { 0, 0, 0 }
    };
    
    int b[3][3] = {
        { 1, 2, 3 },
        { 3, 4, 8 },
        { 9, 6, 7 }
    };

    int c[4][4] = {
        { 1, 3, 1, 5 },
        { 2, 2, 4, 1 },
        { 5, 0, 2, 3 },
        { 0, 6, 1, 2 }
    };

    printf("%d\n%d\n%d\n", gold_gain(a, 3), gold_gain(b, 3), gold_gain(c, 4));
    return 0;
}

/*
GOLD_GAIN
Assignment name  : gold_gain
Expected files   : gold_gain.c
Allowed functions: malloc
--------------------------------------------------------------------------------
ALERT: OPTIMIZED SOLUTION REQUIRED.
Given a matrix which represent a gold mine of n*n dimensions.
Each field in this mine contains a positive integer which is the
amount of gold in tons.
Initially the miner is at first column but can be at any row.
He can move only (right->,right up /,right down\) that is from a given cell,
the miner can move to the cell diagonally up towards the right or right or
diagonally down towards the right.
implement an algorithm able to return the maximum amount of gold he can collect.
The function must be declared as follows:
int gold_gain(int **mine, int n);
Considerations:
- Be careful: the brute force solution won't work on our big input, you have to
find an optimized solution which use dynamic programming.
- You don't have to handle error case, the matrix will be always squared.
- The bigger test we will do is on matrix of 1 000 * 1 000,
it should run in less than 2 seconds.
Example 1:
mine = [
  [ 1, 0, 0 ],
  [ 0, 3, 4 ],
  [ 0, 0, 0 ]
]
n = 3
In this example, your function should return 8,
because taking the following path gain 8:
(0,0) -> (1,1) -> (1,2)
  1   ->   3   ->   4
Example 2:
mine = [
  [ 1, 2, 3 ],
  [ 3, 4, 8 ],
  [ 9, 6, 7 ]
]
n = 3
In this example, your function should return 23,
because taking the following path gain 23:
(2,0) -> (2,1) -> (1,3)
Example 3:
mine = [
  [ 1, 3, 1, 5 ],
  [ 2, 2, 4, 1 ],
  [ 5, 0, 2, 3 ],
  [ 0, 6, 1, 2 ]
]
n = 4
In this example, your function should return 16,
because there is 2 path which give this gain:
(2,0) -> (1,1) -> (1,2) -> (0,3)
or
(2,0) -> (3,1) -> (2,2) -> (2,3)
*/