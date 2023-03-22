class Solution{   
public:
    long long help(string s, string t, int x, int y)
    {
        long long res = 0;
        stack<char> st;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(!st.empty() && st.top() == t[0] && s[i] == t[1])
            {
                st.pop();
                res = res + x;
            }
            else st.push(s[i]);
        }
        s = "";
        while(!st.empty())
        {
            s.push_back(st.top());
            st.pop();
        }
        n = s.size();
        for(int i = 0; i < n; i++)
        {
            if(!st.empty() && st.top() == t[0] && s[i] == t[1])
            {
                st.pop();
                res = res + y;
            }
            else st.push(s[i]);
        }
        return res;
    }
    long long solve(int x, int y, string s)
    {
        long long t1 = help(s, "pr", x, y);
        long long t2 = help(s, "rp", y, x);
        return max(t1, t2);
    }
};
