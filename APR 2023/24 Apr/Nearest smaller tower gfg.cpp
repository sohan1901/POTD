class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int>& arr)
    {
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> s;
        for(int i = 0; i < n; i++)
        {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(!s.empty()) ans[i] = s.top();
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = n-1; i >= 0; i--)
        {
            while(!s.empty() && arr[s.top()] >= arr[i]) s.pop();
            if(!s.empty())
            {
                if(ans[i] == -1) ans[i] = s.top();
                else if(i-ans[i] > s.top()-i) ans[i] = s.top();
                else if(i-ans[i] == s.top()-i)
                {
                    if(arr[ans[i]] > arr[s.top()]) ans[i] = s.top();
                }
            }
            s.push(i);
        }
        return ans;
    }
};
