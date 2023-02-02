unordered_map<int, int> m;
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        int n = order.size();
        for(int i = 0; i < n; i++) m[order[i]] = i;
        vector<string> temp = words;
        sort(temp.begin(), temp.end(), [](string& a, string& b)
        {
            int n = min(a.size(), b.size());
            for(int i = 0; i < n; i++)
            {
                if(m[a[i]] < m[b[i]]) return true;
                else if(m[a[i]] > m[b[i]]) return false;
            }
            if(a.size() <= b.size()) return true;
            return false;
        });
        return temp == words;
    }
};
