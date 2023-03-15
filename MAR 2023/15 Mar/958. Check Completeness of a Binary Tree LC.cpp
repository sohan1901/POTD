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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int qsize = q.size();
            for(int qi = 0; qi < qsize; qi++)
            {
                TreeNode* f = q.front();
                if(f == NULL)
                {
                    while(!q.empty() && q.front() == NULL) q.pop();
                    if(q.empty()) return true;
                    return false;
                }
                q.pop();
                q.push(f->left);
                q.push(f->right);
            }
        }
        return true;
    }
};
