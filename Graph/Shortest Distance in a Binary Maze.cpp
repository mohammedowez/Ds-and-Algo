Input:
grid[][] = {{1, 1, 1, 1},
            {1, 1, 0, 1},
            {1, 1, 1, 1},
            {1, 1, 0, 0},
            {1, 0, 0, 1}}
source = {0, 1}
destination = {2, 2}
Output:
3
Explanation:
1 1 1 1
1 1 0 1
1 1 1 1
1 1 0 0
1 0 0 1
The highlighted part in the matrix denotes the 
shortest path from source to destination cell.

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        
        
        // check for the base case 
        if(source.first==destination.first and destination.second==source.second)
            return 0;
        
        // take a queue in a form of a pair 
        queue<pair<int, pair<int,int>>> q;
            q.push({0,{source.first,source.second}});
            
        int n=grid.size();
        int m=grid[0].size();
        
        // take a new vector to store the destination of the new calculated grid distance 
        
        vector<vector<int>> dist(n,vector<int>(m,1e9));
        dist[source.first][source.second]=0;
        
        
        // four directions, Up, Down, Left and Right
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        
        
        // start the dijastra
        
        while(!q.empty()){
            
            auto it =q.front();
                q.pop();
            
            
            int dis=it.first;
            int r=it.second.first;
            int c=it.second.second;
            
            
                for(int i=0 ;i< 4 ;i++){
                    
                    int newr=r+dr[i];
                    int newc=c+dc[i];
                    
                    if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] 
                == 1 && dis + 1<  dist[newr][newc])
                {
                         
                         dist[newr][newc]=1+dis;
                         
                        // Return the distance until the point when
                        // we encounter the destination cell.
                        if (newr == destination.first && newc == destination.second)
                            return dis + 1;
                        q.push({1 + dis, {newr, newc}});
                    }
                }
        }
        return -1;
    }
};
