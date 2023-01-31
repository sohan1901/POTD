class Solution {
  public:
    int minRepeats(string a, string b)
    {
        string s = a;
        int count = 1;
        while(a.size() < b.size())
        {
            a = a + s;
            count++;
        }
        if(a.find(b) != -1) return count;
        a = a + s;
        count++;
        if(a.find(b) != -1) return count;
        return -1;
    }
};
