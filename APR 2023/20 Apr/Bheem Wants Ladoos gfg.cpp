class Solution
{
public:
    int tl;
    void addladoos(Node* root, int k)
    {
        if(root == NULL || k < 0) return;
        tl = tl + root->data;
        addladoos(root->left, k-1);
        addladoos(root->right, k-1);
    }
    int traverse(Node* root, int target, int k)
    {
        if(root == NULL) return -1;
        if(root->data == target)
        {
            addladoos(root, k);
            return k-1;
        }
        int dist = traverse(root->left, target, k);
        if(dist > -1)
        {
            tl = tl + root->data;
            addladoos(root->right, dist-1);
            return dist-1;
        }
        dist = traverse(root->right, target, k);
        if(dist > -1)
        {
            tl = tl + root->data;
            addladoos(root->left, dist-1);
            return dist-1;
        }
        return -1;
    }
    int ladoos(Node* root, int home, int k)
    {
        tl = 0;
        traverse(root, home, k);
        return tl;
    }
};
