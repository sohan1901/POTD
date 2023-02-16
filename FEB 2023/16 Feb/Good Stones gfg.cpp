class Solution{
public:
    bool dfs(int i, int n, vector<int>& arr, vector<int>& vis)
    {
        if(i < 0 || i >= n || vis[i] == 2) return true;
        if(vis[i] == 1) return false;
        vis[i] = 1;
        if(dfs(i+arr[i], n, arr, vis))
        {
            vis[i] = 2;
            return true;
        }
        return false;
    }
    int goodStones(int n,vector<int> &arr){
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(vis[i] == 0) dfs(i, n, arr, vis);
            if(vis[i] == 2) ans++;
        }
        return ans;
    }  
};
