class Solution {
public:
    
    void dfs(vector<int> adj[],vector<bool> &vis,int node)
    {
        vis[node]=1;
        
        for(auto i:adj[node])
        {
            if(vis[i]==0)
                dfs(adj,vis,i);
        }
        
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(n>connections.size()+1)
            return -1;
        
            
        int count=0;
        
        vector<int> adj[n+1];
        
        for(auto e: connections)
        {
            adj[e[1]].push_back(e[0]);
            adj[e[0]].push_back(e[1]);
        } 
                
        
        vector<bool> vis(n+1,0);
                
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                count++;
                dfs(adj,vis,i);
            }
                    
        } 
                
        return count-1;
    }
};
