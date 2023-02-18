class Solution{   
public:
    int appleSequences(int n, int m, string arr){
        int ans = 0;
        queue<int> q;
        int j = 0;
        int t = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] == 'O')
            {
                if(q.size() < m)
                {
                    q.push(i);
                }
                else
                {
                    t = q.front();
                    q.pop();
                    j = t+1;
                    q.push(i);
                }
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
