class Solution {
  public:
    int checkCompressed(string s, string t)
    {
        int i = 0, j = 0;
        int n = s.size(), m = t.size();
        while(j < m && i < n)
        {
            if(t[j] >= 'A' && t[j] <= 'Z')
            {
                if(t[j] != s[i]) return 0;
                i++;
                j++;
            }
            else
            {
                string str = "";
                while(j < m && t[j] >= '0' && t[j] <= '9')
                {
                    str.push_back(t[j]);
                    j++;
                }
                int num = stoi(str);
                i += num;
            }
        }
        
        return (i == n && j == m);
    }
};
