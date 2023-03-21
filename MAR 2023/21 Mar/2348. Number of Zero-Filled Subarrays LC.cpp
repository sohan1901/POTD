class Solution {
public:
    long long zeroFilledSubarray(vector<int>& arr)
    {
        int i = 0, n = arr.size();
        long long int ans = 0;
        while(i < n)
        {
            long long int t = 0;
            while(i < n && arr[i] != 0) i++;
            while(i < n && arr[i] == 0)
            {
                i++;
                t++;
            }
            ans = ans + (t*(t+1))/2;
        }
        return ans;
    }
};
