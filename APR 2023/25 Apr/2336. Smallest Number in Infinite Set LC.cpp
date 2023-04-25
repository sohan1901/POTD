class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> q;
    unordered_map<int, int> m;
    int i;
    SmallestInfiniteSet() {
        i = 1;
    }
    
    int popSmallest() {
        if(!q.empty() && q.top() < i)
        {
            int t = q.top();
            q.pop();
            m[t] = 0;
            return t;
        }
        return i++;
    }
    
    void addBack(int num) {
        if(m[num] == 0 && num < i)
        {
            m[num] = 1;
            q.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
