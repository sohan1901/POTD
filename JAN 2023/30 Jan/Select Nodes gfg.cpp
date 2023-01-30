class Solution{
  private:
    int count = 0;
  public:
    bool dfs(vector<vector<int>>& adj, int src, vector<bool>& vis)
    {
        vis[src] = true;
        bool select = false;
        for(auto i: adj[src])
        {
            if(!vis[i] && !dfs(adj, i, vis))
            {
                select = true;
            }
        }
        if(select) count++;
        return select;
    }
    int countVertex(int n, vector<vector<int>>edges){
        // code here
        vector<vector<int>> adj(n);
        vector<bool> vis(n, false);
        for(auto i: edges)
        {
            adj[i[0]-1].push_back(i[1]-1);
            adj[i[1]-1].push_back(i[0]-1);
        }
        dfs(adj, 0, vis);
        return count;
    }
};
