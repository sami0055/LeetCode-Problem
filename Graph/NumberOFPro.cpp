class Solution {
public:
     void dfs(int node,vector<int>adj[],int visited[])
    {
        visited[node]=1;
        
        for(auto it:adj[node])
        {
            if(visited[it]==0)
            {
                dfs(it,adj,visited);
            }
        }     
    }
    int findCircleNum(vector<vector<int>>& adj) {
            
            int V=adj.size();
            vector<int>adjlist[V];
       for(int i=0; i<V; i++)
       {
           for(int j=0; j<V; j++)
           {
               if(adj[i][j]==1 && i!=j)
               {
                   adjlist[i].push_back(j);
                   adjlist[j].push_back(i);
               }
           }
       }
       int visited[V];
       for(int i=0; i<V; i++)
       visited[i]=0;
       
       int count=0;
       for(int i=0; i<V; i++)
       {
           if(visited[i]==0)
           {   
               count++;
               dfs(i,adjlist,visited);
               
           }
       }
       return count;
        
    }
};