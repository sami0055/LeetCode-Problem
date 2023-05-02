#include<bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    void dfs(int node,stack<int>&st,vector<int>adj[],int vis[])
    {
        vis[node]=1;
        for(auto it:adj[node])
        {
            if(!vis[it])
            dfs(it,st,adj,vis);
        }
        st.push(node);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   
	   int vis[V]={0};
	   stack<int>st;
	   for(int i=0; i<V; i++)
	   {
	       if(!vis[i])
	       {
	           dfs(i,st,adj,vis);
	       }
	   }
	   vector<int>ans;
	   while(!st.empty())
	   {
	       ans.push_back(st.top());
	       st.pop();
	       
	   }
	   return ans;
	}
};
int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int N,E;
        cin>>E>>N;
        
        vector<int>adj[N];
        for(int i=0; i<E; i++)
        {
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
        }
        Solution obj;
       vector<int>res=obj.topoSort(N,adj);
       for(auto it:res)
       cout<<it<<" ";

       cout<<endl;
    }
}