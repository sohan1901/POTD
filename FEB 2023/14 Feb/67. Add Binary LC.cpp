class Solution {
public:
    string addBinary(string a, string b)
    {
        int t = 0;
        if(a.size() > b.size())
        {
            t = a.size()-b.size();
            b.insert(0, t, '0');
        }
        else if(b.size() > a.size())
        {
            t = b.size()-a.size();
            a.insert(0, t, '0');
        }
        t = 0;
        int n = a.size();
        string ans = "";
        for(int i = n-1; i >= 0; i--)
        {
            if(a[i] == '1' && b[i] == '1')
            {
                if(t == 1)
                {
                    ans.push_back('1');
                }
                else
                {
                    ans.push_back('0');
                    t = 1;
                }
            }
            else if((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
            {
                if(t == 1)
                {
                    ans.push_back('0');
                }
                else
                {
                    ans.push_back('1');
                }
            }
            else
            {
                if(t == 1)
                {
                    ans.push_back('1');
                    t = 0;
                }
                else
                {
                    ans.push_back('0');
                }
            }
        }
        if(t == 1)
        {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
