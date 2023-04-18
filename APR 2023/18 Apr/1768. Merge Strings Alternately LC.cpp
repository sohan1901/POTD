class Solution {
public:
    string mergeAlternately(string& word1, string& word2) {
        string res = "";
        int i = 0, j = 0, n1 = word1.size(), n2 = word2.size();
        while(i < n1 && j < n2)
        {
            res.push_back(word1[i++]);
            res.push_back(word2[j++]);
        }
        while(i < n1) res.push_back(word1[i++]);
        while(j < n2) res.push_back(word2[j++]);
        return res;
    }
};
