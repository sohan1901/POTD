class Solution
{

public:
    int xmod11(string x)
    {
       int n = x.size();
       long long t1 = 0, t2 = 0;
       for(int i = 0; i < n; i++)
       {
           if(i&1) t1 = t1+x[i]-'0';
           else t2 = t2+x[i]-'0';
       }

       long long diff = (t2-t1) % 11;
       if(x.length() % 2 == 0)
          return abs(diff - 11) % 11;
   
       return diff;
    }
};
