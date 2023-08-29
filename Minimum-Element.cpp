#include <bits/stdc++.h> 

int minimumElements(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    for(int T=0; T<= x; T++)
    {
        if(T%nums[0] ==0) dp[0][T] = T/nums[0];
        else dp[0][T] = 1e9;
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int T=0; T<=x; T++)
        {
            int notTake = dp[ind-1][T];
            int take = 1e9;
            if(nums[ind] <= T) take = 1 + dp[ind][T-nums[ind]];

             dp[ind][T] =  min(take, notTake);
        }
    }


    int ans = dp[n-1][x];
    if(ans >= 1e9) return -1;
    return ans;
    
}
