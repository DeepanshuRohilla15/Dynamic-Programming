#include <bits/stdc++.h> 

int f(int ind, int trans, vector<int> &prices, int n, int k,vector<vector<int>> &dp )
{
    if(ind == n || trans == 2*k)
    {
        return 0;
    }
    
    if(dp[ind][trans] != -1) return dp[ind][trans];
    if(trans %2 ==0){
        return dp[ind][trans] = max(-prices[ind] + f(ind+1, trans+1, prices, n, k, dp),
                  0 + f(ind+1, trans, prices, n ,k, dp));
    }
    return dp[ind][trans] =max(prices[ind] + f(ind+1, trans+1, prices, n, k, dp),
               f(ind+1, trans, prices, n, k, dp));
}

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(2*k, -1));
    return f(0,0, prices, n, k, dp);  
}
