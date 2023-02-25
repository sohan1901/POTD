class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int minsofar = prices[0];
        int profit = 0;
        for(int i = 0; i < prices.size(); i++)
        {
            minsofar = min(minsofar, prices[i]);
            profit = max(profit, prices[i]-minsofar);
        }
        return profit;
    }
};
