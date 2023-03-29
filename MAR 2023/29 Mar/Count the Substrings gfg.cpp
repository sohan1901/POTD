class Solution
{
    public:
    int countSubstring(string S)
    {
        int l = 0;
        int u = 0;
        int ans = 0;
        int n = S.size();
        for(int i = 0; i < n; i++)
        {
            l = 0;
            u = 0;
            for(int j = i; j < n; j++)
            {
                if(S[j] >= 'a' && S[j] <= 'z') l++;
                else u++;
                if(l == u) ans++;
            }
        }
        return ans;
    }
};
