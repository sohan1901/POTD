class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<vector<int>> arr;
        for(int i = 0; i < n; i++)
        {
            arr.push_back({capital[i], profits[i]});
        }
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b)
        {
            return a[0]<b[0];
        });
        int i = 0;
        priority_queue<int> q;
        while(k--)
        {
            while(i < n && arr[i][0] <= w) q.push(arr[i++][1]);
            if(q.empty()) break;
            w = w + q.top();
            q.pop();
        }
        return w;
    }
};
