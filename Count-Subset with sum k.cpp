int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, 0));
	for(int i=0; i<n; i++) dp[i][0] = 1;
	if(arr[0] <= k) dp[0][arr[0]] = 1;

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
	return dp[n-1][k]%mod;
}
