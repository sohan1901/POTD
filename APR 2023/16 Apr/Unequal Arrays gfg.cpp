class Solution {
  public:
    long long solve(int n, vector<int> &a, vector<int> &b) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long s1 = 0, s2 = 0;
        vector<int> ao, ae, bo, be;
        for(int i = 0; i < n; i++)
        {
            s1 = s1 + a[i];
            s2 = s2 + b[i];
            if(a[i]&1) ao.push_back(a[i]);
            else ae.push_back(a[i]);
            if(b[i]&1) bo.push_back(b[i]);
            else be.push_back(b[i]);
        }
        if(s1 != s2 || ao.size() != bo.size()) return -1;
        long long ans = 0;
        for(int i = 0; i < ao.size(); i++) ans = ans + abs(ao[i]-bo[i]);
        for(int i = 0; i < ae.size(); i++) ans = ans + abs(ae[i]-be[i]);
        return ans/4;
    }
};
