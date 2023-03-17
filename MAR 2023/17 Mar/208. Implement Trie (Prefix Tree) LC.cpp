struct Node{
    Node* link[26];
    bool flag = false;
};
class Trie {
private: Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word)
    {
        Node* node = root;
        for(int i = 0; i < word.length(); i++)
        {
            if(node->link[word[i]-'a'] == NULL)
            {
                node->link[word[i]-'a'] = new Node();
            }
            node = node->link[word[i]-'a'];
        }
        node->flag = true;
    }
    
    bool search(string word)
    {
        Node* node = root;
        for(int i = 0; i < word.size(); i++)
        {
            if(node->link[word[i]-'a'] == NULL) return false;
            node = node->link[word[i]-'a'];
        }
        return node->flag;
    }
    
    bool startsWith(string prefix)
    {
        Node* node = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            if(node->link[prefix[i]-'a'] == NULL) return false;
            node = node->link[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
