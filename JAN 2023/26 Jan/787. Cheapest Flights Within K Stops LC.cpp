class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<vector<int>>> adj(n);
        for(auto i: flights)
        {
            adj[i[0]].push_back({i[1], i[2]});
        }
        queue<vector<int>> q;
        q.push({src, 0});
        int ans = INT_MAX;
        vector<int> vis(n, INT_MAX);
        vis[src] = 0;
        k = k + 2;
        while(!q.empty() && k--)
        {
            int qsize = q.size();
            for(int qi = 0; qi < qsize; qi++)
            {
                vector<int> t = q.front();
                q.pop();
                if(t[0] == dst)
                {
                    ans = min(ans, t[1]);
                }
                for(auto i: adj[t[0]])
                {
                    if(vis[i[0]] > t[1]+i[1])
                    {
                        vis[i[0]] = t[1] + i[1];
                        q.push({i[0], t[1] + i[1]});
                    }
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};
