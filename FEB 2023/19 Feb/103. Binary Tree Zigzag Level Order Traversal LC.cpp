class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == NULL) return {};
        bool flag = false;
        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty())
        {
            vector<int> t;
            int qsize = q.size();
            for(int qi = 0; qi < qsize; qi++)
            {
                TreeNode* k = q.front();
                q.pop();
                t.push_back(k->val);
                if(k->left != NULL) q.push(k->left);
                if(k->right != NULL) q.push(k->right);
            }
            if(flag) reverse(t.begin(), t.end());
            ans.push_back(t);
            flag = !flag;
        }
        return ans;
    }
};
