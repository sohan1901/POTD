int getMinimumDays(int n,string s, vector<int> &p) {
        int ans = 0;
        if(n == 1) return ans;
        for(int i = 0; i < n; i++)
        {
            int idx = p[i];
            if(idx+1 < n && s[idx] == s[idx+1] && s[idx] != '?')
            {
                s[idx] = '?';
                ans = i+1;
            }
            else if(idx-1 >= 0 && s[idx] == s[idx-1] && s[idx] != '?')
            {
                s[idx] = '?';
                ans = i+1;
            }
        }
        return ans;
    }
