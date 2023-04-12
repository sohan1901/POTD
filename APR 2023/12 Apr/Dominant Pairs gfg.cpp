class Solution{
public:
    int dominantPairs(int n,vector<int> &arr){
        sort(arr.begin(), arr.begin()+(n/2));
        sort(arr.begin()+(n/2), arr.end(), greater<int>());
        int k = n/2;
        int ans = 0;
        for(int i = 0; i < k; i++)
        {
            int t = -1;
            int r = n-1;
            int l = n/2;
            while(l <= r)
            {
                int mid = l+(r-l)/2;
                if(arr[i] >= 5*arr[mid])
                {
                    t = mid;
                    r = mid-1;
                }
                else
                {
                    l = mid+1;
                }
            }
            if(t != -1) ans = ans + n - t;
        }
        return ans;
    }  
};
