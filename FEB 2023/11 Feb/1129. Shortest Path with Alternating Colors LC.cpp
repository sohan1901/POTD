class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto i: redEdges) adj[i[0]].push_back({i[1], 0});
        for(auto i: blueEdges) adj[i[0]].push_back({i[1], 1});
        queue<vector<int>> q;
        q.push({0, -1});
        vector<int> ans(n, -1);
        int t = 0;
        while(!q.empty())
        {
            int qsize = q.size();
            while(qsize--)
            {
                auto f = q.front();
                q.pop();
                if(ans[f[0]] == -1) ans[f[0]] = t;
                for(int i = 0; i < adj[f[0]].size(); i++)
                {
                    if(f[1] != adj[f[0]][i].second && adj[f[0]][i].first != -1)
                    {
                        q.push({adj[f[0]][i].first, adj[f[0]][i].second});
                        adj[f[0]][i].first = -1;
                    }
                }
            }
            t++;
        }
        return ans;
    }
};
