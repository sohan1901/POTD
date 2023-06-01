class Solution {
public:
    bool isSafe(vector<vector<int>>& grid, int i, int j)
    {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == 1) return false;
        grid[i][j] = 1;
        return true;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        int step = 1;
        while(!q.empty())
        {
            int qsize = q.size();
            for(int qi = 0; qi < qsize; qi++)
            {
                int i = q.front().first;
                int j = q.front().second;
                if(i == grid.size()-1 && j == grid[i].size()-1) return step;
                q.pop();
                if(isSafe(grid, i+1, j)) q.push({i+1, j});
                if(isSafe(grid, i-1, j)) q.push({i-1, j});
                if(isSafe(grid, i, j+1)) q.push({i, j+1});
                if(isSafe(grid, i, j-1)) q.push({i, j-1});
                if(isSafe(grid, i+1, j+1)) q.push({i+1, j+1});
                if(isSafe(grid, i+1, j-1)) q.push({i+1, j-1});
                if(isSafe(grid, i-1, j+1)) q.push({i-1, j+1});
                if(isSafe(grid, i-1, j-1)) q.push({i-1, j-1});
            }
            step++;
        }
        return -1;
    }
};
