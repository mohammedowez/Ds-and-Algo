class Solution {
public:
    
    // result vector
    vector<vector<int>>result;
    
    // graph path vector
    vector<int>path;
    
    void dfs(int node, int &lastNode, vector<vector<int>>&graph)
    {
        path.push_back(node);

        // reached final node and push path in to result
        if(node==lastNode) result.push_back(path);
        
        // run DFS for adjacency nodes of current node
        for(int i=0;i<graph[node].size();i++)
            dfs(graph[node][i],lastNode,graph);
        
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
		// graph is already adjacency list of nodes
        // run DFS from start node 0 and set final node n-1 as graph node range is 0 to graph_size -1
        dfs(0,--n,graph);
        
        return result;
    }
};

// another solution

class Solution {
public:
    
    void dfs( vector<int> &vis,vector<vector<int>> &graph, vector<vector<int>> &res,
             int node )
    {
        vis.push_back(node);
        
        if(node==graph.size()-1)
        {
            res.push_back(vis);
           // vis.pop_back();
            //return;
            
        } 
        
        for(auto i : graph[node])
        {
            dfs(vis,graph,res,i);
        } 
        
        vis.pop_back();
        
        
    }
    
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        
        int end=graph.size();
        vector<vector<int>> res;
        
        vector<int> visited;
        
         dfs(visited,graph,res,0);
        
        return res;
        
    }
};
