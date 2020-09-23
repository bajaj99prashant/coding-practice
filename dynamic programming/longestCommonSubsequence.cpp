#include <iostream>
using namespace std;

int tdp[100][100];

int topDownDp(char x[], char y[], int m, int n){
    if (m == 0 || n == 0)
        return 0;

    if (tdp[m-1][n-1] != -1)
        return tdp[m-1][n-1];

    if (x[m-1] == y[n-1])
        return 1 + topDownDp(x, y, m-1, n-1);
    else 
        return max(topDownDp(x, y, m-1, n), topDownDp(x, y, m, n-1));
}

int main(){
    for (int i = 0; i < 100; i++)
        for (int j = 0; j < 100; j++)
            tdp[i][j] = -1;

    char x[] = "ABCDGH";
    char y[] = "AEDFHR";
 
    int m = 0, n = 0;
    m = *(&x+1) - x - 1;
    n = *(&y+1) - y - 1;

    int result = topDownDp(x, y, m, n);
    cout << result;
    return 0;
}

/* 

    A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
    For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”. 
    There are 2^n possible subsequences of the string.
    Brute force solution takes O(n*2^n) time complexity.
    It is basis of file comparison program that outputs the differences between two files.
    The point is here we don't have to find the exact subsequence but we only need to find the length of the subsequence.

*/