class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int i, int j, bool& flag, int& count)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || vis[i][j] == 1 || grid[i][j] == 0) return;
        if(i == 0 || i == grid.size()-1 || j == 0 || j == grid[i].size()-1)
        {
            flag = false;
        }
        vis[i][j] = 1;
        count++;
        dfs(grid, vis, i+1, j, flag, count);
        dfs(grid, vis, i-1, j, flag, count);
        dfs(grid, vis, i, j+1, flag, count);
        dfs(grid, vis, i, j-1, flag, count);
    }
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    bool flag = true;
                    int count = 0;
                    dfs(grid, vis, i, j, flag, count);
                    if(flag)
                    {
                        ans=ans+count;
                    }
                }
            }
        }
        return ans;
    }
};
