class Solution {
  public:
    string removeReverse(string s) {
        // code here
        unordered_map<char, int> m;
        for(auto i: s) m[i]++;
        int i = 0;
        int j = s.size()-1;
        bool flag = true;
        string begin = "";
        string end = "";
        while(i <= j)
        {
            char ch;
            if(flag) ch = s[i++];
            else ch = s[j--];
            if(m[ch] > 1)
            {
                m[ch]--;
                flag = !flag;
            }
            else
            {
                if(flag)
                    begin.push_back(ch);
                else
                    end.push_back(ch);
            }
        }
        reverse(end.begin(), end.end());
        begin.append(end);
        if(!flag) reverse(begin.begin(), begin.end());
        return begin;
    }
};
