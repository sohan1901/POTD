class Solution {
public:
    int help(vector<int>& satisfaction, int i, int j, vector<vector<int>>& dp)
    {
        if(i == satisfaction.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int a = j*satisfaction[i] + help(satisfaction, i+1, j+1, dp);
        int b = help(satisfaction, i+1, j, dp);
        return dp[i][j] = max(a, b);
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return help(satisfaction, 0, 1, dp);
    }
};
