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
    TreeNode* help(vector<int>& inorder, int x, int y, vector<int>& postorder, int a, int b)
    {
        if(x > y || a > b)return NULL;
        TreeNode *node = new TreeNode(postorder[b]);
        int t = x;  
        while(postorder[b] != inorder[t]) t++;
        node->left  = help(inorder, x, t-1, postorder, a, a+t-x-1);
        node->right = help(inorder, t+1, y, postorder, a+t-x, b-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return help(inorder, 0, n-1, postorder, 0, n-1);
    }
};
