class Solution {
public:
    int help(vector<pair<int, int>>& arr, int n, int t, vector<vector<int>>& dp)
    {
        if(n == 0) return 0;
        if(n == 1 && (arr[0].second == arr[t].second || arr[0].first <= arr[t].first)) return arr[0].first;
        if(dp[n][t] != -1) return dp[n][t];
        if(arr[n-1].first <= arr[t].first)
        {
            return dp[n][t] = max(arr[n-1].first+help(arr, n-1, n-1, dp), help(arr, n-1, t, dp));
        }
        return dp[n][t] = help(arr, n-1, t, dp);
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages)
    {
        vector<pair<int, int>> arr;
        int n = ages.size();
        int ts = 0;
        int ta = 0;
        for(int i = 0; i < n; i++)
        {
            ts = max(ts, scores[i]);
            ta = max(ta, scores[i]);
            arr.push_back({scores[i], ages[i]});
        }
        sort(arr.begin(), arr.end(), [](pair<int, int>& a, pair<int, int>& b)
        {
            if(a.second == b.second) return a.first < b.first;
            return a.second < b.second;
        });
        arr.push_back({INT_MAX, INT_MAX});
        vector<vector<int>> dp(n+1, vector<int>(n+2, -1));
        return help(arr, n, n, dp);
    }
};
