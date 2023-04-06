class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, bool& flag)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || vis[i][j] == 1 || grid[i][j] == 1) return;
        if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[i].size()-1)
        {
            flag = false;
            return;
        }
        vis[i][j] = 1;
        dfs(grid, vis, i+1, j, flag);
        dfs(grid, vis, i-1, j, flag);
        dfs(grid, vis, i, j+1, flag);
        dfs(grid, vis, i, j-1, flag);
    }
    int closedIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i = 1; i < grid.size()-1; i++)
        {
            for(int j = 1; j < grid[i].size()-1; j++)
            {
                bool flag = true;
                if(grid[i][j] == 0 && vis[i][j] == 0)
                {
                    dfs(grid, vis, i, j, flag);
                    if(flag)
                    {
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
