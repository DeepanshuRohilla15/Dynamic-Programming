#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> prev(k+1, 0), cur(k+1, 0);
    prev[0] = cur[0] = true;
    prev[arr[0]] = true;

    for(int ind=1; ind<n; ind++)
    {
        for(int target=1; target<=k; target++)
        {
            bool notTake = prev[target];
            bool take = false;
            if(target >= arr[ind]) take = prev[target-arr[ind]]; 

            cur[target] = take || notTake;
        }
        prev = cur;
    }
    return prev[k];
    
}
