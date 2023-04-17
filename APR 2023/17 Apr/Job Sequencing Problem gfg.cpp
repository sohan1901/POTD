class Solution 
{
    public:
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr, arr+n, [](Job& a, Job& b)
        {
            return a.profit>b.profit;
        });
        int count = 0;
        int profit = 0;
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++)
        {
            int t = arr[i].dead;
            while(t--)
            {
                if(m[t] == 0)
                {
                    m[t] = 1;
                    count++;
                    profit = profit + arr[i].profit;
                    break;
                }
            }
        }
        return {count, profit};
    }
};
