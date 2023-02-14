class Solution{   
public:
    map<char, int> m;
    
    
    int help(int n, vector<vector<int>>& colors, char c, vector<vector<int>>& dp)
    {
        if(n == 0) return 0;
        if(n == 1)
        {
            if(c == 'p') return min(colors[0][1], colors[0][2]);
            if(c == 'b') return min(colors[0][0], colors[0][2]);
            if(c == 'y') return min(colors[0][0], colors[0][1]);
            return min(min(colors[0][0], colors[0][1]), colors[0][2]);
        }
        if(dp[n][m[c]] != -1) return dp[n][m[c]];
        if(c == 'p')
        {
            return dp[n][m[c]] = min(colors[n-1][1]+help(n-1, colors, 'b', dp), colors[n-1][2]+help(n-1, colors, 'y', dp));
        }
        if(c == 'y')
        {
            return dp[n][m[c]] = min(colors[n-1][1]+help(n-1, colors, 'b', dp), colors[n-1][0]+help(n-1, colors, 'p', dp));
        }
        if(c == 'b')
        {
            return dp[n][m[c]] = min(colors[n-1][0]+help(n-1, colors, 'p', dp), colors[n-1][2]+help(n-1, colors, 'y', dp));
        }
        return dp[n][m[c]] = min(min(colors[n-1][0]+help(n-1, colors, 'p', dp), colors[n-1][2]+help(n-1, colors, 'y', dp)), colors[n-1][1]+help(n-1, colors, 'b', dp));
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        m['p'] = 0;
        m['b'] = 1;
        m['y'] = 2;
        vector<vector<int>> dp(N+1, vector<int>(3, -1));
        return help(N, colors, 'o', dp);
    }
};
