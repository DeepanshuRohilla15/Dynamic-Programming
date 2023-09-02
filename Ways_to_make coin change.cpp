#include<bits/stdc++.h>

long countWaysToMakeChange(int *a, int n, int value)
{
    vector<long> prev(value+1, 0), cur(value+1, 0);
    for(int T=0; T<=value; T++)
    {
        prev[T] = (T%a[0] == 0);
    }

    for(int ind=1; ind<n; ind++)
    {
        for(int T=0; T<=value; T++)
        {
            long notTake = prev[T]; 
            long take =0;
            if(a[ind] <= T) take = cur[T-a[ind]];

             cur[T] =  take + notTake;
        } 
        prev = cur;
    }

    return prev[value];  
}
