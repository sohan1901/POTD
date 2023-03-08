class Solution {
public:
    long long help(vector<int>& piles, int k)
    {
        if(k == 0) return INT_MAX;
        long long res = 0;
        for(auto i: piles)
        {
            if((i%k) == 0) res = res+(i/k);
            else res = res+1+(i/k);
        }
        return res;
    }
    long long minEatingSpeed(vector<int>& piles, int t) {
        int l = 0;
        int h = 1e9;
        int m;
        while(l < h)
        {
            m = l+(h-l)/2;
            if(help(piles, m) > t) l = m + 1;
            else h = m;
        }
        return l;
    }
};
