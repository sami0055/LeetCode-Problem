//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        // // Create a priority queue for storing the nodes as a pair {dist,node}
        // // where dist is the distance from source to the node. 
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // // Initialising distTo list with a large number to
        // // indicate the nodes are unvisited initially.
        // // This list contains distance from source to the nodes.
        // vector<int> distTo(V, INT_MAX);

        // // Source initialised with dist=0.
        // distTo[S] = 0;
        // pq.push({0, S});

        // // Now, pop the minimum distance node first from the min-heap
        // // and traverse for all its adjacent nodes.
        // while (!pq.empty())
        // {
        //     int node = pq.top().second;
        //     int dis = pq.top().first;
        //     pq.pop();

        //     // Check for all adjacent nodes of the popped out
        //     // element whether the prev dist is larger than current or not.
        //     for (auto it : adj[node])
        //     {
        //         int v = it[0];
        //         int w = it[1];
        //         if (dis + w < distTo[v])
        //         {
        //             distTo[v] = dis + w;
    
        //             // If current distance is smaller,
        //             // push it into the queue.
        //             pq.push({dis + w, v});
        //         }
        //     }
        // }
        // // Return the list containing shortest distances
        // // from source to all the nodes.
        // return distTo;
        
        // =========================Implement Using Set ========================
        
        set<pair<int,int>>st;
        vector<int>dist(V,INT_MAX);
        dist[S]=0;
        st.insert({0,S});
       while(!st.empty()) {
            auto it = *(st.begin()); 
            int node = it.second; 
            int dis = it.first; 
            st.erase(it); 
            
            // Check for all adjacent nodes of the erased
            // element whether the prev dist is larger than current or not.
            for(auto it : adj[node]) {
                int adjNode = it[0]; 
                int edgW = it[1]; 
                
                if(dis + edgW < dist[adjNode]) {
                    // erase if it was visited previously at 
                    // a greater cost.
                    if(dist[adjNode] != 1e9) 
                        st.erase({dist[adjNode], adjNode}); 
                        
                    // If current distance is smaller,
                    // push it into the queue
                    dist[adjNode] = dis + edgW; 
                    st.insert({dist[adjNode], adjNode}); 
                 }
            }
        }
        return dist;
    }
};

   


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends