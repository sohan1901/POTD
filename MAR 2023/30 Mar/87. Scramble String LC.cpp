class Solution {
public:
    unordered_map<string, unordered_map<string, bool>> m;
    bool isScramble(string s1, string s2) {
        if(s1 == s2) return true;
        if(m.find(s1) != m.end() && m[s1].find(s2) != m[s1].end()) return m[s1][s2];
        int n = s1.length();
        int count[26] = {0};
        for(int i = 0; i < n; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        for(int i = 0; i < 26; i++) if(count[i] != 0) return m[s1][s2] = false;
        for(int i = 1; i < n; i++)
        {
            string a = s1.substr(0, i);
            string b = s1.substr(i);
            if(isScramble(a, s2.substr(0, i)) && isScramble(b, s2.substr(i))) return m[s1][s2] = true;
            if(isScramble(a, s2.substr(n-i)) && isScramble(b, s2.substr(0, n-i))) return m[s1][s2] = true;
        }
        return m[s1][s2] = false;
    }
};
