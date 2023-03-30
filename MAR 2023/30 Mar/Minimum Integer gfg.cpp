class Solution {
  public:
    int minimumInteger(int N, vector<int> &A) {
        long long s = 0;
        for(auto i: A) s+= (long long)i;
        sort(A.begin(), A.end());
        int i = 0;
        while(i < N && (long long)A[i]*N<s) i++;
        if(i == N) return -1;
        return A[i];
    }
};
