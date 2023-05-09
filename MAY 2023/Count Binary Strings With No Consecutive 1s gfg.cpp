class Solution {
  public:
    long long mod = 1e9+7;
    //nxn matrix
    vector<vector<long long>> power(vector<vector<long long>>& matrix, long long p, long long n)
    {
        if(p <= 0)
        {
            vector<vector<long long>> ans(n, vector<long long>(n, 0));
            for(int i = 0; i < n; i++) ans[i][i] = 1;
            return ans;
        }
        if(p == 1) return matrix;
        vector<vector<long long>> t = power(matrix, p/2, n);
        vector<vector<long long>> ans(n, vector<long long>(n, 0));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    ans[i][j] = (ans[i][j]%mod + ((t[i][k]%mod)*(t[k][j]%mod))%mod)%mod;
                }
            }
        }
        if(p&1)
        {
            vector<vector<long long>> v = ans;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    ans[i][j] = 0;
                    for(int k = 0; k < n; k++)
                    {
                        ans[i][j] = (ans[i][j]%mod + ((v[i][k]%mod)*(matrix[k][j]%mod))%mod)%mod;
                    }
                }
            }
        }
        return ans;
    }
    int countStrings(long long int N) {
        vector<vector<long long>> matrix = {{1, 1}, {1, 0}};
        vector<vector<long long>> k = power(matrix, N-1, 2);
        return ((2*k[0][0])%mod+k[0][1]%mod)%mod;
        
    }
};
