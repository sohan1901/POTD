class Solution
{
    private:
        const int mod = 1e9+7;
	    int help(string s, int i, int n, vector<int>& dp)
	    {
	        if(i > n || s[i] == '0') return 0;
	        if(i == n || i == n-1) return 1;
	        if(dp[i] != -1) return dp[i];
	        if(s[i] == '1')
	        {
	            if(i+1 < n && s[i+1] >= '0' && s[i+1] <= '9')
	            {
	                if(s[i+1] == '0') return dp[i] = help(s, i+2, n, dp)%mod;
	                return dp[i] = (help(s, i+1, n, dp)%mod + help(s, i+2, n, dp)%mod)%mod;
	            }
	        }
	        if(s[i] == '2')
	        {
	            if(i+1 < n && s[i+1] >= '0' && s[i+1] <= '6')
	            {
	                if(s[i+1] == '0') return dp[i] = help(s, i+2, n, dp)%mod;
	                return dp[i] = (help(s, i+1, n, dp)%mod + help(s, i+2, n, dp)%mod)%mod;
	            }
	        }
	        if(i+1 < n && s[i+1] > '0' && s[i+1] <= '9') return dp[i] = help(s, i+1, n, dp)%mod;
	        return 0;
	    }
	public:
		int CountWays(string str)
		{
		    vector<int> dp(str.size()+1, -1);
		    return help(str, 0, str.size(), dp);
		}
};
