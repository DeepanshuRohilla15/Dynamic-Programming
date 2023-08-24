int mod = 1000000007;
int f(int ind, int sum, vector<int>& arr, vector<vector<int>> &dp)
{

	if(sum==0) return 1;
	if(ind ==0) return (arr[0]==sum);
	if(dp[ind][sum] != -1) return dp[ind][sum];
	int notPick = f(ind-1, sum, arr, dp);
	int pick=0;
	if(arr[ind] <= sum) pick = f(ind-1, sum-arr[ind], arr, dp);

	return dp[ind][sum] = (pick + notPick)%mod;
}

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp)%mod;
}
