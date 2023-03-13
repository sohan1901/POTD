class Solution {
  public:
    long long maxPossibleValue(int N, vector<int> A, vector<int> B)
    {
        long long ans = 0;
        int k = INT_MAX, c = 0;
        for(int i = 0; i < N; i++)
        {
            if(B[i] >= 2) k = min(k, A[i]);
            c = c + (B[i]/2)*2;
            ans = ans + A[i] * (B[i]/2)*2;
        }
        if(c%4 != 0) ans = ans - (2*k);
        return ans;
    }
};
