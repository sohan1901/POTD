class Solution {
public:
    string removeStars(string& s) {
        stack<char> st;
        for(auto i: s)
        {
            if(i != '*') st.push(i);
            else st.pop();
        }
        string res = "";
        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
