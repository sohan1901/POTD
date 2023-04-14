class Solution {
public:
    int lcs(string& s1, string& s2, int n, int m, vector<vector<int>>& dp)
    {
        if(n == 0 || m == 0) return 0;
        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n-1] == s2[m-1])
            return dp[n][m] = 1+lcs(s1, s2, n-1, m-1, dp);
        return dp[n][m] = max(lcs(s1, s2, n-1, m, dp), lcs(s1, s2, n, m-1, dp));
    }
    int longestPalindromeSubseq(string& s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return lcs(s, t, n, n, dp);
    }
};
