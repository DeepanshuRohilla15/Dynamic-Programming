int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt){
    vector<int> prev(w+1, 0), cur(w+1, 0);
    for(int W=0; W<=w; W++)
    {
        prev[W] = ((int)(W/wt[0]))*val[0];
    }
    for(int ind=1; ind<n; ind++)
    {
        for(int W=0; W<=w; W++)
        {
            int notTake = prev[W];
            int take = -1e9;
            if(wt[ind] <= W) take = val[ind] + cur[W-wt[ind]];

            cur[W] =  max(take, notTake);
        }
        prev = cur;
    }

    return prev[w];
}
