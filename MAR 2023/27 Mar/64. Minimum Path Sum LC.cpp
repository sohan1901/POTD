class Solution {
public:
    int help(vector<vector<int>>& grid, int si, int sj, int di, int dj, vector<vector<int>>& dp)
    {
        if(si >= grid.size() || sj >= grid[0].size()) return INT_MAX;
        if(si == di && sj == dj) return grid[si][sj];
        if(dp[si][sj] != -1) return dp[si][sj];
        return dp[si][sj] = grid[si][sj]+min(help(grid, si+1, sj, di, dj, dp), help(grid, si, sj+1, di, dj, dp));
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return help(grid, 0, 0, n-1, m-1, dp);
    }
};
