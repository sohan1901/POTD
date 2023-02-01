class Solution
{   
public:
    map<char, int> m;
    long long int help(int n, int r[], int g[], int b[], int c, vector<vector<long long int>>& dp)
    {
        if(n == 0) return 0;
        if(n == 1)
        {
            if(c == 'r') return min(g[0], b[0]);
            if(c == 'b') return min(g[0], r[0]);
            if(c == 'g') return min(r[0], b[0]);
            return min(min(r[0], g[0]), b[0]);
        }
        if(dp[n][m[c]] != -1) return dp[n][m[c]];
        if(c == 'r')
        {
            return dp[n][m[c]] = min(b[n-1]+help(n-1, r, g, b, 'b', dp), g[n-1]+help(n-1, r, g, b, 'g', dp));
        }
        if(c == 'g')
        {
            return dp[n][m[c]] = min(b[n-1]+help(n-1, r, g, b, 'b', dp), r[n-1]+help(n-1, r, g, b, 'r', dp));
        }
        if(c == 'b')
        {
            return dp[n][m[c]] = min(r[n-1]+help(n-1, r, g, b, 'r', dp), g[n-1]+help(n-1, r, g, b, 'g', dp));
        }
        return dp[n][m[c]] = min(min(r[n-1]+help(n-1, r, g, b, 'r', dp), g[n-1]+help(n-1, r, g, b, 'g', dp)), b[n-1]+help(n-1, r, g, b, 'b', dp));
    }
    long long int distinctColoring(int N, int r[], int g[], int b[])
    {
        m['r'] = 0;
        m['g'] = 1;
        m['b'] = 2;
        vector<vector<long long int>> dp(N+1, vector<long long int>(3, -1));
        return help(N, r, g, b, 'o', dp);
    }
};
