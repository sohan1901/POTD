class Solution {
public:
    void dfs(vector<vector<int>>& adj, set<pair<int, int>>& s, int src, int parent, int& count)
    {
        for(auto i: adj[src])
        {
            if(i != parent)
            {
                if(s.find({src, i}) != s.end()) count++;
                dfs(adj, s, i, src, count);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pair<int, int>> s;
        vector<vector<int>> adj(n);
        for(auto i: connections)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            s.insert({i[0], i[1]});
        }
        int count = 0;
        dfs(adj, s, 0, -1, count);
        return count;
    }
};
