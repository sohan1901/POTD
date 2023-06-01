class Solution
{
	public:
	void dfs(vector<int> adj[], int V, vector<bool>& vis, stack<int>& s)
	{
	    vis[V] = true;
	    for(auto i: adj[V])
	    {
	        if(!vis[i]) dfs(adj, i, vis, s);
	    }
	    s.push(V);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int> s;
	    vector<bool> vis(V, false);
	    for(int i = 0; i < V; i++) if(!vis[i]) dfs(adj, 0, vis, s);
	    vector<int> ans;
	    while(!s.empty())
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    return ans;
	}
