class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N)
    {
        map<int, int> m;
        for(auto i: lines) {
            int u = i[0], v = i[1] + 1;
            m[u]++, m[v]--;
        }
        int ans = 0;
        int sum = 0;
        for(auto i: m)
        {
            sum += i.second;
            ans = max(ans, sum);
        }
        return ans;
    }
};
