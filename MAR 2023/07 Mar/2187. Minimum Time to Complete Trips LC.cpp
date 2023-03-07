class Solution {
public:
    long long help(vector<int>& time, long long t)
    {
        long long res = 0;
        for(auto i: time)
        {
            res = res + (t/i);
        }
        return res;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 0;
        long long h = 1e14;
        long long m;
        while(l < h)
        {
            m = l+(h-l)/2;
            if(help(time, m) >= totalTrips) h = m;
            else l = m+1;
        }
        return l;
    }
};
