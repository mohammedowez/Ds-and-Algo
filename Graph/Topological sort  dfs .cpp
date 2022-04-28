class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	
	void findtopo(int node,stack<int> &st,vector<int> &vis,vector<int> adj[])
	{
	    vis[node]=1;
	    
	    for(auto it : adj[node])
	    {
	        if(vis[it]==0)
	        {
	           findtopo(it,st,vis,adj);
	        }
	    } 
	    
	    st.push(node);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    
	    stack<int> st;
	    vector<int> vis(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(vis[i]==0)
	        {
	            findtopo(i,st,vis,adj);
	        }
	    }
	    
	    
	    vector<int> res;
	    while(!st.empty())
	    {
	        res.push_back(st.top());
	        st.pop();
	    } 
	    
	    return res;
	    
	}
};
