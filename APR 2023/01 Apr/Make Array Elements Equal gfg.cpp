class Solution {
  public:
    long long int minOperations(int N)
    {
        int k = (N+1)/2;
        long long ans;
        if(N%2 == 0) ans = (long long)k*k;
        else ans = (long long)k*(k-1);
        return ans;
    }
};
