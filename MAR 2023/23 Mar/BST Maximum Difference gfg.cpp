class Solution{
public:
    int f1(Node* root, int target, bool& flag, Node*& t)
    {
        if(root == NULL) return 0;
        if(root->data == target)
        {
            t = root;
            flag = true;
            return 0;
        }
        int t1 = root->data + f1(root->left, target, flag, t);
        if(flag) return t1;
        t1 = root->data + f1(root->right, target, flag, t);
        if(flag) return t1;
        return -1;
        
    }
    
    int f2(Node* root)
    {
        if(root == NULL) return INT_MAX;
        if(root->left == NULL && root->right == NULL) return root->data;
        return root->data+min(f2(root->left), f2(root->right));
    }
    
    int maxDifferenceBST(Node *root,int target){
        bool flag = false;
        Node* t = NULL;
        int t1 = f1(root, target, flag, t);
        if(t1 == -1) return -1;
        int t2 = f2(t)-t->data;
        return t1-t2;
    }
};
