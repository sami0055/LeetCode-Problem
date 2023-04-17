class Solution {
  public:
    bool valid(int row,int col,int n,int m,vector<vector<char>>&grid,vector<vector<int>>&visited)
    {
        return row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1' && visited[row][col]==0;
    }
    void bfs(vector<vector<char>> grid, vector<vector<int>>& visited, int row, int col, int n, int m)
    {
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
        visited[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0; i<4; i++)
            {
                int next_row=row+dx[i];
                int next_col=col+dy[i];
                if(valid(next_row,next_col,n,m,grid,visited))
                {
                    visited[next_row][next_col]=1;
                    q.push({next_row,next_col});
                    
                }
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int count=0;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(visited[i][j]==0 && grid[i][j]=='1')
                {
                count++;
                bfs(grid,visited,i,j,n,m);
                }
            }
        }
        return count;
      
    }
};