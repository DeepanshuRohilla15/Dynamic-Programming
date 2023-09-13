#include <bits/stdc++.h> 

int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    vector<int> after(2*k +1, 0), cur(2*k+1, 0);
    
    for(int ind=n-1; ind>=0; ind--){
        for(int trans= 2*k -1; trans>=0; trans--){
            
            if(trans %2 ==0){
                cur[trans] = max(-prices[ind] + after[trans+1],
                        0 + after[trans]);
            }
            else{  cur[trans] =max(prices[ind] + after[trans+1],
                    after[trans]);
            }
        }
        after = cur;
    }
    return after[0];
}
