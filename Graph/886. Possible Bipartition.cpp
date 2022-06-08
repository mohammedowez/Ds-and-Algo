Example 1:

Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4] and group2 [2,3].
Example 2:

Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false

class Solution {
public:
    
    bool bfs(vector<vector<int>> &adj, vector<int> &color,int node)
    {
        // create a queue
        queue<int> qt;
            qt.push(node);
        
        // make the node as visited
        color[node]=1;
        
        
        while(!qt.empty())
        {
            int temp=qt.front();
                qt.pop();
            
            
            for(auto i : adj[temp])
            {
                // check the node is already visitied or not 
                if(color[i]==color[temp])
                    return 0;
                
                // if the color of node is different
                else if(color[i]==-1)
                {
                    color[i]=1-color[temp];
                    qt.push(i);
                }
                
            }
            
        } 
        
        return 1;
        
        
        
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
       
        // adjcent list to store the dislikes
        vector<vector<int> > adj(n+1);
        
        
        // to store the color of vistited 
        vector<int> color(n+1,-1);
        
        
        for(auto i: dislikes)
        {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);   
        }  
        
        
        // check for all the nodes in the adjcent list 
        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                // if it is fasle then its true
                if(!bfs(adj,color,i))
                    return 0;
            } 
        }
         
        
        return 1;
        
        
        
        
        
    }
};
