class Solution {

  public:
    int noConseBits(int n) {
        for(int i = 31; i > 1; i--)
        {
            int a = 1<<i;
            int b = 1<<(i-1);
            int c = 1<<(i-2);
            if((n&a) != 0 && (n&b) != 0 && (n&c) != 0)
            {
                n = n&(~c);
            }
        }
        return n;
    }
};
