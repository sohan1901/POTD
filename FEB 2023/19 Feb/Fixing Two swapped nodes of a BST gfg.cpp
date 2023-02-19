class Solution {
  public:
    void inorder(struct Node* root, vector<int>& t)
    {
        if(root == NULL) return;
        inorder(root->left, t);
        t.push_back(root->data);
        inorder(root->right, t);
    }
    void build(struct Node*& root, vector<int>& t, int& i)
    {
        if(root == NULL) return;
        build(root->left, t, i);
        root->data = t[i++];
        build(root->right, t, i);
    }
    struct Node *correctBST(struct Node *root) {
        // code here
        vector<int> t;
        inorder(root, t);
        sort(t.begin(), t.end());
        int k = 0;
        build(root, t, k);
        return root;
    }
};
