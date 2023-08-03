#include<bits/stdc++.h>
using namespace std;

int f(int ind, vector<int> &heights , vector<int> &dp)
{
    if(ind == 0) return 0;
    if(dp[ind] != -1) return dp[ind];
    int left = dp[ind-1] + abs(heights[ind] - heights[ind-1]);
    int right = INT_MAX;
    if(ind > 1)
    {
        right = dp[ind-2] + abs(heights[ind] - heights[ind-2]);
    }
    return dp[ind] = min(left, right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}