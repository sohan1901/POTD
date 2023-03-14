/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void help(TreeNode* root, int k, int& t)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            k = k*10 + root->val;
            t = t + k;
            return;
        }
        k = k*10 + root->val;
        help(root->left, k, t);
        help(root->right, k, t);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        help(root, 0, ans);
        return ans;
    }
};
