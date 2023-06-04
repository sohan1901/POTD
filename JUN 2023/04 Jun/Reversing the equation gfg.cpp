class Solution
{
  public:
    string reverseEqn (string str)
        {
            string s = "";
            int n = str.size()-1;
            while(n >= 0)
            {
                string t = "";
                while(n >= 0 && str[n] >= '0' && str[n] <= '9') t.push_back(str[n--]);
                reverse(t.begin(), t.end());
                s.append(t);
                if(n >= 0) s.push_back(str[n--]);
            }
            return s;
        }
};
