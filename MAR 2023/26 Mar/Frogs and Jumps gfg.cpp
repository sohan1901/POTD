class Solution {
  public:
    int unvisitedLeaves(int N, int leaves, int frogs[]) {
        vector<bool> t(leaves+1, false);
        t[0] = true;
        for(int i = 0; i < N; i++)
        {
            if(t[frogs[i]] == false)
            {
                for(int j = frogs[i]; j < t.size(); j = j+frogs[i])
                {
                    t[j] = true;
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < leaves+1; i++) if(!t[i]) ans++;
        return ans;
    }
};
