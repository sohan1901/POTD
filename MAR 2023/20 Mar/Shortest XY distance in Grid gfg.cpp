class Solution {
  public:
    int shortestXYDist(vector<vector<char>> grid, int N, int M) {
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(N,vector<bool>(M,0));
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<M;j++)
            {
                if(grid[i][j]=='Y')
                {
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        int dx[4]={-1,0,1,0};
        int dy[4]={0,-1,0,1};
        int steps=0;
        while(!q.empty())
        {
            int qsize=q.size();
            while(qsize--)
            {
                 auto it=q.front();
                 q.pop();
                 int x=it.first,y=it.second;
                 
                 if(grid[x][y]=='X') return steps;
                 
                 for(int k=0;k<4;k++)
                 {
                     int adji=x+dx[k],adjj=y+dy[k];
                     if(adji>=0 && adjj>=0 && adji<N && adjj<M && !visited[adji][adjj])
                     {
                         q.push({adji,adjj});
                         visited[adji][adjj]=true;
                     }
                 }
            }
           steps++;
        }
        return -1;
    }
};
