class Solution {
  public:
  const int mod = 1e9+7;
    int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0) return 0;
        if(i == grid.size()-1 && j == grid[0].size()-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = (dfs(i+1, j, grid, dp)%mod + dfs(i, j+1, grid, dp)%mod)%mod;
        
    }
    int uniquePaths(int n, int m, vector<vector<int>> &grid) {
        n--;
        m--;
        if(grid[0][0] == 0 || grid[n][m] == 0) return 0;
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return dfs(0, 0, grid, dp);
    }
};
