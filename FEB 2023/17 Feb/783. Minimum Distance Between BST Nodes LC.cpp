class Solution {
public:
    int help(TreeNode* root, int& prev, int& ans)
    {
        if(root == NULL) return 0;
        if(root->left != NULL) help(root->left, prev, ans);
        if(prev != -1)
            ans = min(ans, root->val-prev);
        prev = root->val;
        if(root->right != NULL) help(root->right, prev, ans);
        return ans;
    }
    int minDiffInBST(TreeNode* root) {
        int ans = INT_MAX;
        int prev = -1;
        return help(root, prev, ans);
    }
};
