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
    void help(TreeNode*& root, bool goLeft, int& ans, int cans)
    {
        if(root == NULL) return;
        ans = max(ans, cans);
        if(goLeft)
        {
            help(root->left, false, ans, cans+1);
            help(root->right, true, ans, 1);
        }
        else
        {
            help(root->right, true, ans, cans+1);
            help(root->left, false, ans, 1);
        }
    }
    int longestZigZag(TreeNode*& root) {
        int ans = 0;
        help(root, true, ans, 0);
        help(root, false, ans,0);
        return ans;
    }
};
