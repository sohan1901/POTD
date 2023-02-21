class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0;
        int h = nums.size()-1;
        int m;
        while(l < h)
        {
            m = l+(h-l)/2;
            if((m%2 == 0 && nums[m] == nums[m+1]) || (m%2 == 1 && nums[m] == nums[m-1])) l = m+1;
            else h = m;
        }
        return nums[l];
    }
};
