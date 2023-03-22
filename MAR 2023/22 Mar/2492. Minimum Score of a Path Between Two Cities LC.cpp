class Solution {
public:
    int help(vector<vector<vector<int>>>& adj, int src, int dest)
    {
        int res = INT_MAX;
        queue<int> q;
        vector<int> vis(adj.size(), 0);
        q.push(0);
        while(!q.empty())
        {
            auto t = q.front();
            q.pop();
            for(auto i: adj[t])
            {
                if(vis[i[1]] == 0)
                {
                    q.push(i[1]);
                    vis[i[1]] = 1;
                }
                res = min(res, i[0]);
            }
        }
        return res;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>> adj(n);
        for(auto i: roads)
        {
            adj[i[0]-1].push_back({i[2], i[1]-1});
            adj[i[1]-1].push_back({i[2], i[0]-1});
        }
        return help(adj, 0, n-1);
    }
};
