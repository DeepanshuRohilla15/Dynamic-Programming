#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
	if(arr[0] !=0 && arr[0] <= k) dp[0][arr[0]] = 1;

	for(int ind=1; ind<n; ind++)
	{
		for(int sum=0; sum<=k; sum++)
		{
			int notPick = dp[ind-1][sum];
			int pick=0;
			if(arr[ind] <= sum) pick = dp[ind-1][sum-arr[ind]];

			 dp[ind][sum] = (pick + notPick)%mod;
		}
	}
	return dp[n-1][k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum=0;
    for(auto &it: arr) totSum += it;
    if(totSum - d <0 || (totSum-d)%2) return false;
    return findWays(arr, (totSum-d)/2);
}
