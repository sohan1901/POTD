class Solution{
public:	
	int help(int* arr, int n, vector<int>& dp)
	{
	    if(n == 0) return 0;
	    if(n == 1) return arr[0];
	    if(dp[n] != -1) return dp[n];
	    return dp[n] = max(arr[n-1]+help(arr, n-2, dp), help(arr, n-1, dp));
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n+1, -1);
	    return help(arr, n, dp);
	}
};
