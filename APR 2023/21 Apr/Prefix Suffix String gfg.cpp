class Solution{
public:
    int prefixSuffixString(vector<string> &s1,vector<string> s2){
        int i=0,j=0;
        int n=s1.size(), m=s2.size();
        int ans=0;
        
        while(i<n && j<m){
            if(s1[i].find(s2[j])!=-1){
                int len=s2[j].size();
                string pre=s1[i].substr(0,len);
                string suff=s1[i].substr(s1[i].size()-len);
                
                if(pre==s2[j] || suff==s2[j]){
                    ans++;
                    i=0;
                    j++;
                }
                else{
                    i++;
                }
            }
            else
            i++;
        }
        return ans;
    }
};
