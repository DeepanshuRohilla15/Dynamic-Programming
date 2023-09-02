#include <bits/stdc++.h> 

int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	
	int n = arr.size();
	vector<int> prev(k+1, 0), cur(k+1, 0);
	if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
	if(arr[0] !=0 && arr[0] <= k) prev[arr[0]] = 1;

	for(int ind=1; ind<n; ind++)
	{
		for(int sum=0; sum<=k; sum++)
		{
			int notPick = prev[sum];
			int pick=0;
			if(arr[ind] <= sum) pick = prev[sum-arr[ind]];

			 cur[sum] = (pick + notPick);
		}
        prev = cur;
	}
	return prev[k];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum=0;
    for(auto &it: arr) totSum += it;
    if(totSum - d <0 || (totSum-d)%2) return false;
    return findWays(arr, (totSum-d)/2);
}

int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
}
