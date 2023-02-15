class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k)
    {
        vector<int> ans;
        int n = num.size();
        int c = 0;
        for(int i = n-1; i >= 0; i--)
        {
            int t = k%10;
            k = k/10;
            int sum = num[i]+t+c;
            ans.push_back(sum%10);
            c = sum/10;
        }
        while(k != 0)
        {
            int t = k%10;
            k = k/10;
            int sum = t+c;
            ans.push_back(sum%10);
            c = sum/10;
        }
        if(c != 0) ans.push_back(c);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
