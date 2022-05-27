Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3
class Solution {
public:
    
    void dfs(int node ,vector<vector<int>> &v,vector<bool> &vis,
            int n)
    {
        
        vis[node]=1;
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0 and v[node][i]==1)
                 dfs(i,v,vis,n);
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& v) {
        
        int n=v.size();
        vector<bool> visited(n,0);
        
        int cnt=0;
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                dfs(i,v,visited,n);
                cnt++;
            }
        } 
        
        return cnt;
        
    }
};
