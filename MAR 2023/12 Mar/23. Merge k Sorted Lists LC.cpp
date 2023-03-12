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
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& list) {
        int n = list.size();
        multiset<int> s;
        for(int i = 0; i < n; i++)
        {
            while(list[i] != NULL)
            {
                s.insert(list[i]->val);
                list[i] = list[i]->next;
            }
        }
        ListNode* t = new ListNode(0);
        ListNode* ans = t;
        for(auto i:s)
        {
            t->next = new ListNode(i);
            t = t->next;
        }
        return ans->next;
    }
};
