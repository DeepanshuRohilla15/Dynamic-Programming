#include<bits/stdc++.h>

int minimizeCost(int n, int k, vector<int> &height){
      vector<int>dp(n,0);
      dp[0]=0;
      for(int i=1;i<n;++i)
      {
            int minCost=INT_MAX;
            for(int j=1;j<=k;++j)
            {
              if(i-j>=0){
             int jump= dp[i-j]+abs(height[i]-height[i-j]);
             minCost=min(minCost,jump);
             }
             dp[i] = minCost;
            }
      }
      return dp[n-1];
}
