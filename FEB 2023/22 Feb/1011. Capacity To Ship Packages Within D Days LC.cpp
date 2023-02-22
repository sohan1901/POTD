class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int h = 0;
        for(auto i: weights)
        {
            l = max(l, i);
            h = h + i;
        }
        int m;
        while(l < h)
        {
            m = l+(h-l)/2;
            if(help(weights, m) > days) l = m+1;
            else h = m;
        }
        return l;
    }
    int help(vector<int>& weights, int m)
    {
        int days = 1;
        int capacity = 0;
        for(auto i: weights)
        {
            if(capacity+i <= m) capacity = capacity+i;
            else
            {
                capacity = i;
                days++;
            }
        }
        return days;
    }
};
