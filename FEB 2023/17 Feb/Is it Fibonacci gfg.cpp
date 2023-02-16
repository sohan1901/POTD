class Solution {
  public:
    long long solve(int N, int K, vector<long long>& arr) {
        if(N-1 < K) return arr[N-1];
        vector<long long> t;
        long long sum = 0;
        for(auto i: arr)
        {
            sum = sum + i;
            t.push_back(i);
        }
        int j = 0;
        for(int i = K; i < N; i++)
        {
            t.push_back(sum);
            sum = sum - t[j++] + t.back();
        }
        return t.back();
    }
};
