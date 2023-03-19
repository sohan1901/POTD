class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A)
    {
        vector<int> ans(N, 0);
        unordered_set<int> s;
        s.insert(A[0]);
        for(int i = 1; i < N; i++)
        {
            ans[i] = s.size();
            s.insert(A[i]);
        }
        s.clear();
        s.insert(A[N-1]);
        for(int i = N-2; i >= 0; i--)
        {
            ans[i] = ans[i]-s.size();
            s.insert(A[i]);
        }
        return ans;
    }
};
