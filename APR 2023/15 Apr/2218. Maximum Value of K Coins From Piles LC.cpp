class Solution {
public:
    int help(vector<vector<int>>& piles, int t, int k, vector<vector<int>>& dp)
    {
        if(t == piles.size() || k == 0) return 0;
        if(dp[t][k] != -1) return dp[t][k];
        int fres = 0;
        int s = piles[t].size();
        for(int i = 0; i < min(k+1, s); i++)
        {
            int tres = 0;
            tres = tres + piles[t][i] + help(piles, t+1, k-i, dp);
            fres = max(fres, tres);
        }
        return dp[t][k] = fres;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        for(int i = 0; i < n; i++)
        {
            int t = 0;
            for(int j = 0; j < piles[i].size(); j++)
            {
                t = t + piles[i][j];
                piles[i][j] = t-piles[i][j];
            }
            piles[i].push_back(t);
        }
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return help(piles, 0, k, dp);
    }
};
