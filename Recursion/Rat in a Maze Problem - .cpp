Input:
N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}
Output:
DDRDRR DRDDRR
Explanation:
The rat can reach the destination at 
(3, 3) from (0, 0) by two paths - DRDDRR 
and DDRDRR, when printed in sorted order 
we get DDRDRR DRDDRR.
  
  
  class Solution{
    public:
    vector<string> res;
    
    void dfs(int row,int col,vector<vector<int>> &m,int n,string str)
    {
        if(row<0 or col<0 or row>=n or col>=n or m[row][col]==0)
            return;
            
        if(row==n-1 and col==n-1)
        {
            res.push_back(str);
            return;
        } 
        
        m[row][col]=0;
        dfs(row+1,col,m,n,str+"D");
        dfs(row,col+1,m,n,str+"R");
        dfs(row-1,col,m,n,str+"U");
        dfs(row,col-1,m,n,str+"L");
        
        m[row][col]=1;
        
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        // Your code goes here
        
        res.clear();
        if(m[0][0]==0 or m[n-1][n-1]==0)
            return res;
        
        string str="";
        
        dfs(0,0,m,n,str);
        
        return res;
        
    }
};
