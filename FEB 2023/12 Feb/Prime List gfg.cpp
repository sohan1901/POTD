class Solution{
public:
    bool isprime(int n)
    {
        if(n <= 1) return false;
        if(n == 2 || n == 3) return true;
        if(n%2 == 0) return false;
        for(int i = 3; i*i <= n; i=i+2)
        {
            if(n%i == 0) return false;
        }
        return true;
    }
    int nearestPrime(int n)
    {
        int i = 0;
        while(true)
        {
            if(isprime(n-i)) return n-i;
            if(isprime(n+i)) return n+i;
            i++;
        }
    }
    Node *primeList(Node *head){
        Node* temp = head;
        while(temp != NULL)
        {
            temp->val = nearestPrime(temp->val);
            temp = temp->next;
        }
        return head;
    }
};
