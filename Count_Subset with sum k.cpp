int mod = 1000000007;

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	
	int n = arr.size();
	vector<int> prev(k+1, 0), cur(k+1, 0);
	prev[0] = cur[0] = 1;
	if(arr[0] <= k) prev[arr[0]] = 1;

	for(int ind=1; ind<n; ind++)
	{
		for(int sum=0; sum<=k; sum++)
		{
			int notPick = prev[sum];
			int pick=0;
			if(arr[ind] <= sum) pick = prev[sum-arr[ind]];

			 cur[sum] = (pick + notPick)%mod;
		}
		prev = cur;
	}
	return prev[k]%mod;
}
