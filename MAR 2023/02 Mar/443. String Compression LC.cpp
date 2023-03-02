class Solution {
public:
    int compress(vector<char>& chars)
    {
        if(chars.size() == 1) return 1;
        int ans = 0;
        int i = 0;
        int j = 0;
        int n = chars.size();
        while(i < n)
        {
            int count = 1;
            while(i < n-1 && chars[i] == chars[i+1])
            {
                i++;
                count++;
            }
            if(count == 1)
            {
                chars[j++] = chars[i];
                ans++;
                i++;
            }
            else
            {
                cout<<i<<endl;
                chars[j++] = chars[i++];
                string s = to_string(count);
                for(auto i: s)
                    chars[j++] = i;
            }
        }
        if(chars[n-1] != chars[n-2]) ans++;
        cout<<j<<endl;
        return j;
    }
};
