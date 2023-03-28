class Solution{
    public:
    
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        long long ans = 0;
        
        int mid = n;
        while(1){
            int low = 0, high = mid-1;
            
            int cost = -1; 
            while(low <= high){
                mid = (low+high)/2;
                int curCost = shop.get(mid);
                if(curCost > cost && curCost <= k){
                    cost = curCost; 
                    low = mid+1;
                }
                else
                    high = mid-1;
            }
            
            if(cost == -1 || cost > k) 
                break; 
            
            ans += k/cost;
            k %= cost;
        }
    
        return ans;
    }

};
