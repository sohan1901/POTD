class Solution {
public:
    int dfs(vector<vector<int>>& adj, int src, int parent, int seats, long long& ans)
    {
        int people = 1;
        for(auto i: adj[src])
        {
            if(i != parent)
                people = people+dfs(adj, i, src, seats, ans);
        }
        if(src != 0)
        {
            ans = ans + (people/seats);
            if(people%seats != 0) ans++;
        }
        return people;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size()+1;
        vector<vector<int>> adj(n);
        for(auto i: roads)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        long long ans = 0;
        dfs(adj, 0, 0, seats, ans);
        return ans;
    }
};
