class Solution {
public:
    bool check(int start,int v,int color[],vector<int> adj[]){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            
            int node=q.front();
                q.pop();
                
            
            for(auto i: adj[node]){
                
                if(color[i]==-1){
                    color[i]= !color[node];
                    q.push(i);
                } 
                else if(color[i]==color[node])
                    return 0;
            }

        } 
        
        return 1;
        
    }
    
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    
	    // to check for all the components in the graph
	   int color[V];
	   for(int i=0;i<V;i++)
            color[i]=-1;
	    
	   for(int i=0;i<V;i++){
	       if(color[i]==-1){
	           if(check(i,V,color,adj)==false)
	            return false;
	       }
	   }
	   
	   return 1;
	}

};
