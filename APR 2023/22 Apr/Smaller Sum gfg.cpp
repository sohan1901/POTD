class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        vector<pair<int, int>> a;
        for(int i = 0; i < n; i++) a.push_back({arr[i], i});
        sort(a.begin(), a.end());
        long long t = a[0].first;
        vector<long long> res(n, 0);
        for(int i = 1; i < n; i++)
        {
            if(a[i].first != a[i-1].first) res[a[i].second] = t;
            else res[a[i].second] = res[a[i-1].second]; 
            t = t+a[i].first;
        }
        return res;
    }
};
