
https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-of-nearest-cell-having-1


class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
	    int col=grid[0].size();
	    
	    vector<vector<int>> vis(row,vector<int> (col,0));
	    vector<vector<int>> dis(row,vector<int> (col,0));
	    
	    queue<pair<pair<int,int>,int>> q;
	    
	    for(int i=0;i<row;i++)
	    {
	        for(int j=0;j<col;j++)
	        {
	            if(grid[i][j]==0){
	                q.push({{i,j},0});
	                vis[i][j]=0;
	            } 
	            else 
	                vis[i][j]=1;
	        }
	    } 
	    
	    int drow[4]={-1,0,1,0};
	    int dcol[4]={0,1,0,-1};
	    
	    while(!q.empty()){
	        
	        int nrow=q.front().first.first;
	        int ncol=q.front().first.second;
	        int steps=q.front().second;
	        q.pop();
	        
	        dis[nrow][ncol]=steps;
	        
	        for(int i=0;i<4;i++){
	            int n=nrow+drow[i];
	            int m=ncol+dcol[i];
	            
	            if(m>=0 and n>=0 && m<col and n<row){
	                if(vis[n][m]==1){
	                    vis[n][m]=0;
	                    q.push({{n,m},steps+1});
	                }
	            }
	        } 
	        
	            
	        
	    } 
	    
	    return dis;
    }
};
