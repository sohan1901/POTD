class Solution {
public:
    int bfs(vector<vector<int>>& adj, int src, vector<bool>& vis)
    {
        queue<int> q;
        q.push(src);
        vis[src] = true;
        int count = 1;
        while(!q.empty())
        {
            int t = q.front();
            q.pop();
            for(auto i: adj[t])
            {
                if(!vis[i] && count++)
                {
                    q.push(i);
                    vis[i] = true;
                }
            }
        }
        return count;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto i: edges)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> vis(n, false);
        vector<long long> temp;
        for(int i = 0; i < n; i++)
        {
            if(!vis[i]) temp.push_back(bfs(adj, i, vis));
        }
        long long ans = 0;
        for(auto i: temp)
        {
            ans = ans + ((n-i)*i);
        }
        return ans/2;
    }
};
