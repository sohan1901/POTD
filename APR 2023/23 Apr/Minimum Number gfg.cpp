class Solution{
public:
    int minimumNumber(int n,vector<int> &arr){
        int ans = arr[0];
        for(auto i: arr) ans = __gcd(ans, i);
        return ans;
    }
};
