class Solution {
public:
    int partitionString(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        char ch = s[0];
        while(i < n)
        {
            unordered_map<char, int> m;
            while(i < n && m.find(s[i]) == m.end())
            {
                m[s[i++]]++;
                ch = s[i];
            }
            ans++;
        }
        return ans;
    }
};
