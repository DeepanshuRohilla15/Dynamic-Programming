int maximumProfit(vector<int> &values, int n, int fee)
{
	// Write your code here.
	vector<long> ahead(2,0), cur(2,0);

    ahead[0] = ahead[1] = 0;

    for(int ind=n-1; ind>=0; ind--){
        for(int buy=0; buy<=1; buy++){
            long profit=0;
            if(buy){
                profit = max(-values[ind] - fee + ahead[0],
                            0 + ahead[1]); 
            }
            else{
                profit = max(values[ind] + ahead[1],
                            0 + ahead[0]);
            }
             cur[buy] = profit;
        }
        ahead = cur;
    }

    return ahead[1];
}
