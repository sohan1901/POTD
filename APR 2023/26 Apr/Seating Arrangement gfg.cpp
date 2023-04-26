class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats)
    {
        int count = 0;
        int l1 = -1;
        for(int i = 0; i < m; i++)
        {
            if(seats[i] == 1)
            {
                int empty = i-l1-1;
                if(l1 == -1) count += empty/2;
                else count += (empty-1)/2;
                l1 = i;
            }
        }
        if(seats[m-1] != 1)
        {
            int empty = m-l1-1;
            if(l1 == -1) count += (empty+1)/2;
            else count += empty/2;
        }
        return count>=n;
    }
};
