class Solution {
  public:
    int equalSum(int N, vector<int> &A) {
        int sum = 0;
        for(auto i: A) sum = sum + i;
        int t = 0;
        for(int i = 0; i < N; i++)
        {
            sum = sum - A[i];
            if(sum == t) return i+1;
            t = t + A[i];
        }
        return -1;
    }
};
