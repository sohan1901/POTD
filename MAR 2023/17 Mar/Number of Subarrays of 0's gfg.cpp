long long int no_of_subarrays(int n, vector<int> &arr) {
    int i = 0;
    long long int ans = 0;
    while(i < n)
    {
        long long int t = 0;
        while(i < n && arr[i] == 1) i++;
        while(i < n && arr[i] == 0)
        {
            i++;
            t++;
        }
        ans = ans + (t*(t+1))/2;
    }
    return ans;
}
