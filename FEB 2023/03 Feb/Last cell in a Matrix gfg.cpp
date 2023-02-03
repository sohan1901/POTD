class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        //code here
        char c = 'r';
        int i = 0;
        int j = 0;
        while(i < R && i >= 0 && j < C && j >= 0)
        {
            if(matrix[i][j] == 1)
            {
                if(c == 'r')
                {
                    matrix[i][j] = 0;
                    c = 'd';
                    i++;
                }
                else if(c == 'u')
                {
                    matrix[i][j] = 0;
                    c = 'r';
                    j++;
                }
                else if(c == 'd')
                {
                    matrix[i][j] = 0;
                    c = 'l';
                    j--;
                }
                else if(c == 'l')
                {
                    matrix[i][j] = 0;
                    c = 'u';
                    i--;
                }
            }
            else
            {
                if(c == 'u') i--;
                else if(c == 'r') j++;
                else if(c == 'd') i++;
                else if(c == 'l') j--;
            }
            
        }
        if(i < 0) i = 0;
        else if(j < 0) j = 0;
        else if(i == R) i = R-1;
        else if(j == C) j = C-1;
        return {i, j};
    }
};
