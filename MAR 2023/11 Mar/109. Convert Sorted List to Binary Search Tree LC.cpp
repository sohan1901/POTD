/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode*> t;
        for(ListNode* temp = head; temp != NULL; temp = temp->next)
        {
            t.push_back(temp);
        }
        return help(t, 0, t.size()-1);
    }
    TreeNode* help(vector<ListNode*>& t, int l, int h)
    {
        if(l > h) return NULL;
        int mid = l+(h-l)/2;
        TreeNode* root = new TreeNode(t[mid]->val);
        root->left = help(t, l, mid-1);
        root->right = help(t, mid+1, h);
        return root;
    }
};
