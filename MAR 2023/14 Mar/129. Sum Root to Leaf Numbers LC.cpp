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
    void help(TreeNode* root, string s, int& t)
    {
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL)
        {
            s.push_back(root->val+'0');
            t = t + stoi(s);
        }
        s.push_back(root->val+'0');
        help(root->left, s, t);
        help(root->right, s, t);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        help(root, "", ans);
        return ans;
    }
};
