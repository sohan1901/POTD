class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int n = pushed.size();
        int i = 0;
        int j = 0;
        while(i < n)
        {
            while(i < n && pushed[i] != popped[j])
            {
                st.push(pushed[i]);
                i++;
            }
            if(i != n) st.push(pushed[i]);
            if(st.top() != popped[j]) return false;
            while(!st.empty() && j < n && st.top() == popped[j])
            {
                st.pop();
                j++;
            }
            i++;
        }
        if(!st.empty()) return false;
        return true;
    }
};
