class Solution {
public:
    int binarysearch(vector<int>& nums, int l, int h)
    {
        int m;
        while(l < h)
        {
            m = l+(h-l)/2;
            if(nums[m] == 1) h = m;
            else l = m+1;
        }
        if(nums[l] == 1) return l;
        return INT_MAX;
    }
    vector<int> findMaxRow(vector<vector<int>> mat, int N) {
        int t, k = INT_MAX, h = N-1, r = 0;
        for(int i = 0; i < N; i++)
        {
            t = binarysearch(mat[i], 0, h);
            if(t < k)
            {
                r = i;
                k = t;
                h = t;
            }
        }
        if(k != INT_MAX) return {r, N-k};
        return {0, 0};
    }
};
