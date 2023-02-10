class Solution{
public:
    int maxInstance(string s){
        unordered_map<int, int> m;
        for(auto i: s) m[i]++;
        return min(min(m['b'], m['a']), min(min(m['l']/2, m['o']/2), m['n']));
    }
};
