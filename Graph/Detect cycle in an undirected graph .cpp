class Solution {
  public:
    // Function to detect cycle in an undirected graph.
   bool cycle(int node, int parent, vector<int>& vis, vector<int> adj[])
   {
     vis[node]=1;
     for(auto it: adj[node])
     {
         if(!vis[it]){
             cycle(it,node,vis,adj);
         }
         else if(it != parent)
            return 1;
     }
     return 0;
 }
 
   // Function to detect cycle in an undirected graph.
   bool isCycle(int V, vector<int> adj[]) 
   {
       // Code here
       vector<int> vis(V+1,0);
       for(int i=1;i<V;++i)
       {
           if(!vis[i])
           {
               if(cycle(i,-1,vis,adj))return true;
           }
       }
       return 0;
   }
};


