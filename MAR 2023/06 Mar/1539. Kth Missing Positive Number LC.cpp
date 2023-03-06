class Solution {
public:
    int search(vector<int>& arr, int target, int l, int h)
    {
        int m;
        while(l <= h)
        {
            m = l+(h-l)/2;
            if(arr[m] == target) return m;
            else if(arr[m] < target) l = m+1;
            else h = m-1;
        }
        return -1;
    }
    int findKthPositive(vector<int>& arr, int k)
    {
        int i = 0;
        int t = 1;
        int l = 0;
        int h = arr.size()-1;
        while(i < k)
        {
            int s = search(arr, t, l, h);
            if(s == -1) i++;
            else l = s;
            if(i != k) t++;
        }
        return t;
    }
};
