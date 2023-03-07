class Solution{
  public:
    int maxLevelSum(Node* root) {
        int ans = INT_MIN;
        int t;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            t = 0;
            int qsize = q.size();
            for(int qi = 0; qi < qsize; qi++)
            {
                Node* f = q.front();
                q.pop();
                if(f->left != NULL) q.push(f->left);
                if(f->right != NULL) q.push(f->right);
                t = t + f->data;
            }
            ans = max(ans, t);
        }
        return ans;
    }
};
