#include<bits/stdc++.h>
int f(int i, int j, int* arr, vector<vector<int>> &dp)
{
    if(i==j) return 0;
    int mini = 1e8;
    if(dp[i][j] != -1) return dp[i][j];
    for(int k = i; k < j; k++)
    {
        int steps = (arr[i-1]* arr[k]* arr[j]) + f(i, k, arr, dp) + f(k+1, j, arr, dp);
        mini = min(mini, steps);
    }
    return dp[i][j] = mini;
}

int matrixChainMultiplication(int* arr, int n) {
    // Write your code here
    vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
    return f(1, n, arr, dp);
}
