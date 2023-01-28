class Solution{
    public:
    bool help(string s1, string s2, unordered_map<string, bool>& dp)
    {
        if(s1 == s2) return true;
        if(dp.find(s1+"_"+s2) != dp.end()) return dp[s1+"_"+s2];
        int n = s1.size();
        for(int i = 1; i < n; i++)
        {
            if(help(s1.substr(0, i), s2.substr(0, i), dp) && help(s1.substr(i, n-i), s2.substr(i, n-i), dp))
            {
                return dp[s1+"_"+s2] = true;
            }
            if(help(s1.substr(0, i), s2.substr(n-i, i), dp) && help(s1.substr(i, n-i), s2.substr(0, n-i), dp))
            {
                return dp[s1+"_"+s2] = true;
            }
        }
        return dp[s1+"_"+s2] = false;
    }
    bool isScramble(string s1, string s2)
    {
        unordered_map<string, bool> dp;
        return help(s1, s2, dp);
    }    
};
