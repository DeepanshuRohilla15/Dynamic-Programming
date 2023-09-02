#include<bits/stdc++.h>

long countWaysToMakeChange(int *a, int n, int value)
{
    vector<vector<long>> dp(n, vector<long>(value+1, 0));
    for(int T=0; T<=value; T++)
    {
        dp[0][T] = (T%a[0] == 0);
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int T=0; T<=value; T++)
        {
            long notTake = dp[ind-1][T]; 
            long take =0;
            if(a[ind] <= T) take = dp[ind][T-a[ind]];

             dp[ind][T] =  take + notTake;
        }
    }

    return dp[n-1][value];  
}
