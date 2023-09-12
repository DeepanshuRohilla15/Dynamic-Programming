#include<bits/stdc++.h>

int f(int ind, int trans, vector<int>& prices, int n, vector<vector<int>> &dp)
{
    if(ind == n || trans == 4) return 0;

    if(dp[ind][trans] != -1) return dp[ind][trans];
    if(trans % 2 == 0){
        return dp[ind][trans] = max(-prices[ind] + f(ind+1, trans+1, prices, n, dp),
                  0 + f(ind+1, trans, prices, n, dp));
    }
    else {
        return dp[ind][trans] =  max(prices[ind] + f(ind+1, trans+1, prices, n, dp),
                    f(ind+1, trans, prices, n, dp));
    }
}

int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return f(0,0, prices, n, dp);
    // Write your code here.
}
