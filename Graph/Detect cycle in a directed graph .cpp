class Solution {
  public:
    // Function to detect cycle in a directed graph.
    
    bool cycledfs(int node,vector<int> adj[],int vis[],int dfsvis[])
    {
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it: adj[node])
        {
          // if it is not visited then call dfs 
            if(vis[it]==0)
            {
                if(cycledfs(it,adj,vis,dfsvis))
                    return 1;
            }
          // if the path is visited the the graph is cyclic
             else if(dfsvis[it]) 
                return true;
        } 
         dfsvis[node]=0;
        
        return 0;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        int vis[V]={0};
        int dfsvis[V]={0};
        
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                if(cycledfs(i,adj,vis,dfsvis))
                    return 1;
            }
        } 
        
        return 0;
    }
};
