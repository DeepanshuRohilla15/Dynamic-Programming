class Solution {
public:
    int lengthOfLIS(vector<int>& arr) {
        int n = arr.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int ind=n-1; ind>=0; ind--){
        for(int prev_ind=ind-1; prev_ind>=-1; prev_ind--){
            int len = 0 + dp[ind+1][prev_ind + 1];
            if(prev_ind == -1 || arr[ind] > arr[prev_ind]){
                len = max(len, 1 + dp[ind+1][ind+1]);
            } 
             dp[ind][prev_ind+1] = len;
        }
    }
    return dp[0][0];
    }
};
