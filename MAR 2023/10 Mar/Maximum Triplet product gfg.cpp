class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
        long long mmax = LLONG_MIN;
        long long smax = LLONG_MIN;
        long long tmax = LLONG_MIN;
        long long mmin = LLONG_MAX;
        long long smin = LLONG_MAX;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > mmax)
            {
                tmax = smax;
                smax = mmax;
                mmax = arr[i];
            }
            else if(arr[i] > smax)
            {
                tmax = smax;
                smax = arr[i];
            }
            else if(arr[i] > tmax) tmax = arr[i];
            if(arr[i] < mmin)
            {
                smin = mmin;
                mmin = arr[i];
            }
            else if(arr[i] < smin) smin = arr[i];
        }
        long long ans = max(mmax*smax*tmax, mmax*mmin*smin);
        return ans;
    }
};
