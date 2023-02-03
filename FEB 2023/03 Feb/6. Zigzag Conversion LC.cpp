class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<vector<char>> t(numRows);
        bool flag = true;
        int c = 0;
        for(auto i: s)
        {
            if(flag)
            {
                t[c].push_back(i);
                if(c == numRows-1)
                {
                    c--;
                    flag = false;
                }
                else c++;
            }
            else
            {
                t[c].push_back(i);
                if(c == 0)
                {
                    c++;
                    flag = true;
                }
                else c--;
            }
        }
        string ans = "";
        for(auto i: t)
            for(auto j: i)
                ans.push_back(j);
        return ans;
    }
};
