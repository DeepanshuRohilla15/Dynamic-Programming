int f(int ind, int N, vector<int> &price, vector<vector<int>> &dp)
{
	if(ind==0) return N* price[0];
	if(dp[ind][N] != -1) return dp[ind][N];
	int notTake = f(ind-1, N, price, dp);
	int take = INT_MIN;
	int rodLength = ind+1;
	if(rodLength <= N){
		take = price[ind] + f(ind, N - rodLength, price, dp);
	}
	return dp[ind][N] = max(notTake, take);
}

int cutRod(vector<int> &price, int n)
{
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	return f(n-1, n, price, dp);
	// Write your code here.

}
