
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    
    void dfs(int row,int col,vector<vector<int>>&mat,vector<vector<int>>&vis,int dx[],int dy[])
    {
        vis[row][col]=1;
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0; i<4; i++)
        {
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && mat[nrow][ncol]==1 && !vis[nrow][ncol])
            {
                dfs(nrow,ncol,mat,vis,dx,dy);
            }
        
        }
        
        
    }
    int numberOfEnclaves(vector<vector<int>> &grid, vector<vector<int>>&vis) {
       
       
       int n=grid.size();
       int m=grid[0].size();
        int dx[4]={0,0,-1,1};
         int dy[4]={-1,1,0,0};
       for(int j=0; j<m; j++)
       {
           if(!vis[0][j] && grid[0][j]==1)
           {
               dfs(0,j,grid,vis,dx,dy);
           }
           if(!vis[n-1][j] && grid[n-1][j]==1)
           {
               dfs(n-1,j,grid,vis,dx,dy);
           }
       }
       for(int i=0; i<n; i++)
       {
           if(!vis[i][0] && grid[i][0]==1)
           {
               dfs(i,0,grid,vis,dx,dy);
           }
           if(!vis[i][m-1] && grid[i][m-1]==1)
           {
               dfs(i,m-1,grid,vis,dx,dy);
           }
       }
       int count=0;
       for(int i=0; i<n; i++)
       {
           for(int j=0; j<m; j++)
           {
               if(!vis[i][j] && grid[i][j]==1)
               {
                   count++;
               }
           }
       }
       return count;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
         vector<vector<int>>vis(n,vector<int>(m,0));
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid,vis) << endl;
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<vis[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<grid[i][j]<<" ";
            }
            cout<<endl;
        }

    }
}