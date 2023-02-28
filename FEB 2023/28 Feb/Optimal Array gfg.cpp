class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        vector<int> ans(n, 0);
        for(int i = 1; i < n; i++)
        {
            ans[i] = ans[i-1]+a[i]-a[i/2];
        }
        return ans;
    }
};
