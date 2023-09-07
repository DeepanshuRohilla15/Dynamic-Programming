class Solution {
public:
    int mod = (int)(1e9+7);
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> prev(m+1, 0);
        
        prev[0] = 1;
        
        for(int i=1; i<=n; i++)
        {
            for(int j=m; j>=1; j--)
            {
                if(s[i-1] == t[j-1])
                {
                    prev[j] = prev[j-1]%mod + prev[j]%mod;
                }    
            }
           
        }
        return (prev[m]);
    }
};
