class Solution {
  public:
    vector<int> solveQueries(int N, int num, vector<int> &A, vector<vector<int>> &Q) {
        int ma = 0;
        for(auto i: A) ma = max(ma, i);
        vector<vector<int>> t(N, vector<int>(ma+1, 0));
        for(int i = 0; i < N; i++)
        {
            t[i][A[i]]++;
            for(int j = i+1; j < N; j++)
            {
                if(A[j] == A[i]) t[i][A[i]]++;
            }
        }
        vector<int> ans;
        for(int i = 0; i < Q.size(); i++)
        {
            int a = Q[i][0], b = Q[i][1], k = Q[i][2], count = 0;
            for(int j = a; j <= b; j++)
            {
                if(t[j][A[j]] == k) count++;
            }
            ans.push_back(count);
        }
        return ans;
    }
};
