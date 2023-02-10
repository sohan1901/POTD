class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 1) return false;
        grid[i][j] = 1;
        return true;
    }
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(grid[i][j] == 1)
                    q.push({i, j});
        if(q.size() == n*n) return -1;
        while(!q.empty())
        {
            int qsize = q.size();
            while(qsize--)
            {
                auto [t1, t2] = q.front();
                q.pop();
                if(isSafe(grid, t1+1, t2))q.push({t1+1, t2});
                if(isSafe(grid, t1-1, t2))q.push({t1-1, t2});
                if(isSafe(grid, t1, t2+1))q.push({t1, t2+1});
                if(isSafe(grid, t1, t2-1))q.push({t1, t2-1});
            }
            ans++;
        }
        return ans-1;
    }
};
