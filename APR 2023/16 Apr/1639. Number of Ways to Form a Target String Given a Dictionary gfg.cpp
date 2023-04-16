#define ll long long

class Solution {
public:
    const ll MOD = 1e9 + 7;
    int n;

    int go(vector<vector<ll>>& freq, vector<vector<ll>>& mem, string& target, int w, int t)
    {
        if(t >= target.size()) return 1;
        if(w >= n) return 0;
        if(mem[w][t] > -1) return mem[w][t];
        
        int cur = target[t] - 'a';     
        return mem[w][t] = (go(freq, mem, target, w + 1, t) + ((freq[w][cur] * go(freq, mem, target, w + 1, t + 1)) % MOD)) % MOD;
    }
    int numWays(vector<string>& words, string target) {
        int i, j, m = words.size();
        n = words[0].size();
        vector<vector<ll>> freq(n, vector<ll>(26, 0)), mem(n + 1, vector<ll>(target.size() + 1, -1));

        for(i=0; i<m; i++)
            for(j=0; j<n; j++)
                freq[j][words[i][j] - 'a']++;
        
        return go(freq, mem, target, 0, 0);
    }
};
