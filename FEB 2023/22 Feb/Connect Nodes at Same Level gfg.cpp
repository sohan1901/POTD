class Solution{
    public:
    void connect(Node *&root)
    {
        Node* t;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int qsize = q.size();
            for(int qi = 0; qi < qsize; qi++)
            {
                t = q.front();
                q.pop();
                if(t->left != NULL) q.push(t->left);
                if(t->right != NULL) q.push(t->right);
                if(!q.empty()) t->nextRight = q.front();
                else t->nextRight = NULL;
            }
            t->nextRight = NULL;
        }
    }    
};
