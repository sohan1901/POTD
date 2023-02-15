class Solution{   
public:
    bool valid(int i, int j, vector<vector<bool>>& vis, int prev, vector<vector<int>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        return i>=0&&i<n&&j>=0&&j<m&&(!vis[i][j])&&prev<=mat[i][j];
    }
    int water_flow(vector<vector<int>> &mat,int N,int M){
        queue<pair<int, pair<int, int>>> q;
        vector<vector<bool>> vis(N, vector<bool>(M, false));
        for(int i = 0; i < N; i++)
        {
            q.push({mat[i][0], {i, 0}});
            vis[i][0] = true;
        }
        for(int i = 1; i < M; i++)
        {
            q.push({mat[0][i], {0, i}});
            vis[0][i] = true;
        }
        map<pair<int, int>, bool> indian;
        while(!q.empty())
        {
            int val = q.front().first;
            pair<int, int> p = q.front().second;
            int i = p.first;
            int j = p.second;
            q.pop();
            indian[{i, j}] = true;
            vis[i][j] = true;
            if(valid(i+1, j, vis, val, mat))
            {
                q.push({mat[i+1][j], {i+1, j}});
                vis[i+1][j] = true;
            }
            if(valid(i-1, j, vis, val, mat))
            {
                q.push({mat[i-1][j], {i-1, j}});
                vis[i-1][j] = true;
            }
            if(valid(i, j+1, vis, val, mat))
            {
                q.push({mat[i][j+1], {i, j+1}});
                vis[i][j+1] = true;
            }
            if(valid(i, j-1, vis, val, mat))
            {
                q.push({mat[i][j-1], {i, j-1}});
                vis[i][j-1] = true;
            }
        }
        vector<vector<bool>> vi(N, vector<bool>(M, false));
        for(int i = 0; i < N; i++)
        {
            q.push({mat[i][M-1], {i, M-1}});
            vi[i][M-1] = true;
        }
        for(int i = 0; i < M-1; i++)
        {
            q.push({mat[N-1][i], {N-1, i}});
            vi[N-1][i] = true;
        }
        int ans = 0;
        while(!q.empty())
        {
            int val = q.front().first;
            pair<int, int> p = q.front().second;
            int i = p.first;
            int j = p.second;
            q.pop();
            if(indian[{i, j}]) ans++;
            vi[i][j] = true;
            if(valid(i+1, j, vi, val, mat))
            {
                q.push({mat[i+1][j], {i+1, j}});
                vi[i+1][j] = true;
            }
            if(valid(i-1, j, vi, val, mat))
            {
                q.push({mat[i-1][j], {i-1, j}});
                vi[i-1][j] = true;
            }
            if(valid(i, j+1, vi, val, mat))
            {
                q.push({mat[i][j+1], {i, j+1}});
                vi[i][j+1] = true;
            }
            if(valid(i, j-1, vi, val, mat))
            {
                q.push({mat[i][j-1], {i, j-1}});
                vi[i][j-1] = true;
            }
        }
        return ans;
    }
};
