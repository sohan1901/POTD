class Solution {
public:
    int countOdds(int low, int high) {
        int a = high-low+1;
        if(a%2 == 0) return a/2;
        else if(low%2 == 0 && high%2 == 0) return a/2;
        else return (a/2)+1;
    }
};
