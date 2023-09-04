int cutRod(vector<int> &price, int n)
{
	vector<int> prev(n+1, 0), cur(n+1, 0);
	for(int N=0; N<=n; N++)
	{
		prev[N] = N* price[0];
	}

	for(int ind=1; ind<n; ind++)
	{
		for(int N=0; N<=n; N++)
		{
			int notTake = prev[N];
			int take = INT_MIN;
			int rodLength = ind+1;
			if(rodLength <= N){
				take = price[ind] + cur[N - rodLength];
			}
			cur[N] = max(notTake, take);
		}
		prev = cur;
	}
	return prev[n];
	// Write your code here.
}
