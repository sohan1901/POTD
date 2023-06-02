class Solution {
public:
    void dfs(vector<vector<int>>& graph, int start, vector<bool>& vis, int& count)
    {
        vis[start] = true;
        count++;
        for(int i = 0; i < graph[start].size(); i++)
        {
            if(!vis[graph[start][i]]) dfs(graph, graph[start][i], vis, count);
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++)
        {
            long long x1 = bombs[i][0];
            long long y1 = bombs[i][1];
            long long r1 = bombs[i][2];
            for(int j = 0; j < n; j++)
            {
                if(i != j)
                {
                    long long x2 = abs(bombs[j][0]-x1);
                    long long y2 = abs(bombs[j][1]-y1);
                    if(x2*x2+y2*y2 <= r1*r1) graph[i].push_back(j);
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            vector<bool> vis(n, false);
            int count = 0;
            dfs(graph, i, vis, count);
            ans = max(ans, count);
        }
        return ans;
    }
};
