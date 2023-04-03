class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans = 0;
        sort(people.begin(), people.end());
        int i = 0, j = people.size()-1;
        while(i <= j)
        {
            if(j-1 >= 0 && people[j]+people[j-1] <= limit)
            {
                ans++;
                j = j-2;
            }
            else
            {
                if(people[j]+people[i] <= limit)
                {
                    ans++;
                    j--;
                    i++;
                }
                else
                {
                    ans++;
                    j--;
                }
            }
        }
        return ans;
    }
};
