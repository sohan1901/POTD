class Solution{
    public:
    bool wifiRange(int N, string S, int X){
        int l = -1;
        for(int i = 0; i < N; i++)
        {
            if(S[i] == '1')
            {
                if(i-X-1 > l) return false;
                l = i+X;
            }
        }
        if(l < N-1) return false;
        return true;
    }
};
