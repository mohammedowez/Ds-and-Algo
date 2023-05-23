class Solution {
  public:
    void topoSort(int node ,vector<pair<int,int>> adj[],stack<int> &st,vector< int> &vis){
        
        vis[node]=1;
        
        for(auto it :  adj[node]){
            int u=it.first;
            if(vis[u]==0)
                topoSort(u,adj,st,vis);
        } 
        
        st.push(node);
    }
    
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        
        // Shortest path in Directed Acyclic Graph - means topological sort 
        //first make the adjacent list 
        vector<pair<int,int>> adj[N];
        
        for(int i=0 ;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
        } 
        
        // make the visited array
        vector< int> vis(N,0);
        
        // make use of topogical sort in an array of all the integers to find the shortest path
        stack<int> st;
        for(int i=0;i<N;i++){
            
            if(vis[i]==0){
                topoSort(i,adj,st,vis);
            }
        }
         
         
        // make a distance array
        vector<int> dist(N,1e9);
        dist[0]=0;
        
        while(!st.empty())
        {
            auto node =st.top();
                st.pop();
                
            for(auto it : adj[node])
            {
                int v=it.first;
                int wt=it.second;
                
                if(dist[node]+wt<dist[v]){
                    dist[v]=dist[node]+wt;
                }
            }
        } 
         for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
        
        return dist;
        
    }
};
