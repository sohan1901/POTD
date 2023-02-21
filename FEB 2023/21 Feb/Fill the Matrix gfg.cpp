class Solution{   
public:
    bool isSafe(int n, int m, int x, int y)
    {
        if(x < 1 || y < 1 || x > n || y > m) return false;
        return true;
    }
    int minIteration(int n, int m, int x, int y){    
        // code here
        queue<pair<int, int>> q;
        int ans = 0;
        vector<vector<int>> s(n, vector<int>(m, 0));
        q.push({x, y});
        s[x-1][y-1] = 1;
        while(!q.empty())
        {
            int qsize = q.size();
            for(int qi = 0; qi < qsize; qi++)
            {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                if(isSafe(n, m, i+1, j) && s[i][j-1] == 0)
                {
                    s[i][j-1] = 1;
                    q.push({i+1, j});
                }
                if(isSafe(n, m, i-1, j) && s[i-2][j-1] == 0)
                {
                    s[i-2][j-1] = 1;
                    q.push({i-1, j});
                }
                if(isSafe(n, m, i, j+1) && s[i-1][j] == 0)
                {
                    s[i-1][j] = 1;
                    q.push({i, j+1});
                }
                if(isSafe(n, m, i, j-1) && s[i-1][j-2] == 0)
                {
                    s[i-1][j-2] = 1;
                    q.push({i, j-1});
                }
            }
            ans++;
        }
        return ans-1;
    }
};
