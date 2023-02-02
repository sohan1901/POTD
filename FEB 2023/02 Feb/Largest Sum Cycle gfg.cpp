class Solution
{
  public:
  long long res = -1;
  void dfs(int node, int prevNode, vector<vector<int>>& g, vector<long long>& sum, vector<long long>& vis, vector<long long>& pathVis) {
      
      sum[node] = sum[prevNode] + node;
      vis[node] = 1;pathVis[node] = 1;
      
      for(auto &it: g[node]) {
          if(pathVis[it]) {
              res = max(res, sum[node] - sum[it] + it);
          }
          else if(!vis[it]){
              dfs(it,node,g,sum,vis,pathVis);
          }
      }
      
      pathVis[node] = 0;
  }
  long long largestSumCycle(int N, vector<int> Edge) {
      
      vector<vector<int>> g(N);
      for(int i = 0; i < N; i++) {
          if(Edge[i] != -1) {
              g[i].push_back(Edge[i]);
          }
      }
      
      vector<long long> sum(N+1), vis(N), pathVis(N);
      for(int i = 0; i < N; i++) {
          if(!vis[i]) {
              dfs(i,N,g,sum,vis,pathVis);
          }
      }
      return res;
  }
};
