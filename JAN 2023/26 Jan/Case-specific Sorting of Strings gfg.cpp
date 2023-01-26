    string caseSort(string str, int n)
    {
        vector<char> cap, lil;
        for (auto c: str) {
            if (c<'a') cap.push_back(c);
            else lil.push_back(c);
        }
        sort(cap.begin(), cap.end());
        sort(lil.begin(), lil.end());
        int c=0, l=0;
        for (int i=0; i<str.length(); i++) {
            if (str[i]<'a')
                str[i] = cap[c++];
            else 
                str[i] = lil[l++];
        }
        return str;
    }
