class Solution {
  public:
    int totalTime(int n, vector<int> &arr, vector<int> &time)
    {
        int cnt = 0;
        map<int,bool> m;
        for(int i = 0; i < n; i++)
        {
            m[arr[i]] = 0;
        }
        
        m[arr[0]] = 1;
        for(int i = 0; i < n-1; i++)
        {
            if(m[arr[i+1]] == 0)
            {
                cnt++;
                m[arr[i+1]] = 1;
            }
            else
            {
                cnt = cnt+time[arr[i+1]-1];
            }
        }
        return cnt;
    }
};
