#include <bits/stdc++.h> 

int knapsack(vector<int> wt, vector<int> val, int n, int maxWeight) 
{
	vector<int> prev(maxWeight+1, 0), cur(maxWeight+1,0);
	for(int W= wt[0]; W<=maxWeight; W++)
	{
		prev[W] = val[0];
	}

	for(int ind=1; ind<n; ind++)
	{
		for(int W=0; W<= maxWeight; W++)
		{
			int notTake = prev[W];
			int take = INT_MIN;
			if(wt[ind]<= W)
			{
				take = val[ind] + prev[W-wt[ind]];
			}
		    cur[W] = max(take, notTake);
		}
		prev = cur;
	}

	
	return prev[maxWeight];
	
}
