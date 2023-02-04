class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> t1(26, 0), t2(26, 0);
        for(auto i: s1) t1[i - 'a']++;
        int n1 = s1.size();
        int n2 = s2.size();
        for(int i = 0; i < n2; i++)
        {
            t2[s2[i]-'a']++;
            if(i >= n1) t2[s2[i - n1]-'a']--;
            if(t1 == t2) return true;
        }
        return false;
    }
};
