class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& vis, int start)
    {
        vis[start] = true;
        for(auto i: adj[start])
        {
            if(!vis[i]) dfs(adj, vis, i);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(isConnected[i][j] == 1) adj[i].push_back(j);
            }
        }
        vector<bool> vis(n, false);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i])
            {
                dfs(adj, vis, i);
                ans++;
            }
        }
        return ans;
    }
};
