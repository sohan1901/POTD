class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
            
    }  
    void addNum(int val)
    {
        s.insert(val);
    } 
    vector<vector<int>> getIntervals()
    {
        vector<vector<int>> ans;
        int start = -1;
        int end = -1;
        for ( auto  &item: s)
        {
            if (start == -1)
            {
                start = item;
                end = item;
            }
            else if (item == end + 1)
            {
                end = item;
            }
            else
            {
                ans.push_back({start, end});
                start = end = item;
            }
        }
        if (start != -1) ans.push_back({start, end});
        return ans;
    }
};
