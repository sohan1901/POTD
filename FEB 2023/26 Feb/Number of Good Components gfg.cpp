class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int src, int& count, bool& flag, int size, vector<int>& vis)
    {
        if(vis[src] == 1) return;
        vis[src] = 1;
        count++;
        if(size != adj[src].size()) flag = false;
        for(auto i: adj[src])
            dfs(adj, i, count, flag, size, vis);
    }
    int findNumberOfGoodComponent(int V, vector<vector<int>>& adj) {
        // code here
        vector<int> vis(V+1, 0);
        int ans = 0;
        for(int i = 1; i <= V; i++)
        {
            if(vis[i] == 0)
            {
                int count = 0;
                bool flag = true;
                dfs(adj, i, count, flag, adj[i].size(), vis);
                if(flag && count == adj[i].size()+1) ans++;
            }
        }
        return ans;
    }
};
