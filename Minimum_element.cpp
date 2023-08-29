#include <bits/stdc++.h> 

int minimumElements(vector<int> &nums, int x)
{
    int n = nums.size();
    vector<int> prev(x+1, 0), cur(x+1, 0);
    for(int T=0; T<= x; T++)
    {
        if(T%nums[0] ==0) prev[T] = T/nums[0];
        else prev[T] = 1e9;
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int T=0; T<=x; T++)
        {
            int notTake = prev[T];
            int take = 1e9;
            if(nums[ind] <= T) take = 1 + cur[T-nums[ind]];

             cur[T] =  min(take, notTake);
        }
        prev = cur;
    }


    int ans = prev[x];
    if(ans >= 1e9) return -1;
    return ans;   
}
