Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
  
  
  
  class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++)
        {
            
            if(color[i]==0)
            {
                color[i]=-1;
                queue<int> qt;
                    qt.push(i);
                
                
                while(!qt.empty())
                {
                    
                    int neighbour=qt.front();
                        qt.pop();
                    
                    
                    for(auto  x : graph[neighbour])
                    {
                       
                        // If the neighbor has the same color - can't bipartite.
                        if(color[x]==color[neighbour])
                            return 0;
                        
                        // Color neighbor with opposite color
                        
                        else if(color[x]==0)
                        {
                            color[x]=-color[neighbour];
                            qt.push(x);
                        }
                        
                    }
                }
                
                
            }
        } 
        
        return 1;
    }
};
