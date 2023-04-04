int minSteps(string str) {
    int t = 0;
    int n = str.size();
    int i = 0;
    while(i < n)
    {
        while(i < n && str[i] == str[i+1]) i++;
        i++;
        t++;
    }
    return (t+2)/2;
}
