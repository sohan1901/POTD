class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int t = INT_MIN;
        vector<bool> ans(candies.size());
        for(auto i: candies) t = max(i, t);
        for(int i = 0; i < candies.size(); i++) (candies[i]+extraCandies >= t) ? ans[i] = true: ans[i] = false;
        return ans;
    }
};
