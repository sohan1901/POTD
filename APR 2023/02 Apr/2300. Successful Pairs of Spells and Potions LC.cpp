class Solution {
public:
    int search(vector<int>& arr, long long target, int k)
    {
        int l = 0;
        int r = arr.size()-1;
        int m;
        while(l < r)
        {
            m = l+(r-l)/2;
            if(target <= (long long)k*arr[m]) r = m;
            else l = m+1;
        }
        return l;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        sort(potions.begin(), potions.end());
        vector<int> ans;
        for(int i = 0; i < n; i++)
        {
            int k = search(potions, success, spells[i]);
            if(k == m-1)
            {
                if((long long)potions[k]*spells[i] >= success) ans.push_back(1);
                else ans.push_back(0);
            }
            else ans.push_back(m-k);
        }
        return ans;
    }
};
