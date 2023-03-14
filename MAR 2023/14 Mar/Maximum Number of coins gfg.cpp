class Solution{
    private:
    int mcm(vector<int>& arr, int l, int r, vector<vector<int>>& dp)
    {
        if(l >= r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int ans = 0;
        for(int i = l; i < r; i++)
        {
            ans = max(ans, (mcm(arr, l, i, dp)+mcm(arr, i+1, r, dp)+(arr[l-1]*arr[i]*arr[r])));
        }
        return dp[l][r] = ans;
    }
    public:
    int maxCoins(int N, vector <int> &a)
    {
        a.insert(a.begin(), 1);
        a.push_back(1);
        vector<vector<int>> dp(N+2, vector<int>(N+2, -1));
        return mcm(a, 1, N+1, dp);
    }
};
