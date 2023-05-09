class Solution {
public:
    vector<int> help(vector<vector<int>>& m, int r1, int r2, int c1, int c2, int size)
    {
        vector<int> ans;
        while(ans.size() < size)
        {
            for(int i = c1; i < c2; i++)
            {
                if(ans.size() < size)
                {
                    ans.push_back(m[r1][i]);
                }
                else
                {
                    break;
                }
            }
            for(int i = r1+1; i < r2; i++)
            {
                if(ans.size() < size)
                {
                    ans.push_back(m[i][c2-1]);
                }
                else
                {
                    break;
                }
            }
            for(int i = c2-2; i >= c1; i--)
            {
                if(ans.size() < size)
                {
                    ans.push_back(m[r2-1][i]);
                }
                else
                {
                    break;
                }
            }
            for(int i = r2-2; i > r1; i--)
            {
                if(ans.size() < size)
                {
                    ans.push_back(m[i][c1]);
                }
                else
                {
                    break;
                }
            }
            r1++;
            c1++;
            r2--;
            c2--;
        }
        return ans;
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        return help(matrix, 0, matrix.size(), 0, matrix[0].size(), matrix.size()*matrix[0].size());
    }
};
