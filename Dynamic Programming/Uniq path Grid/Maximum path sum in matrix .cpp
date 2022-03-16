Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

Example 1:

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. 
It gives the sum = 1009.

Example 2:

Input: N = 2
Matrix = {{2, 2},
          {2, 2}}
Output: 4
Explaination: No matter which path is 
chosen, the output is 4.

class Solution{
public:
    int solve(int i,int j,int n, vector<vector<int> > &dp, vector<vector<int> > &m)
    {
        if(j<0 or j>=n)
            return -1e9;
        
        if(i==0)
            return m[0][j];
            
        if(dp[i][j]!=-1)
            return dp[i][j];
            
        
        int down=m[i][j]+solve(i-1,j,n,dp,m);
        
        int left=m[i][j]+solve(i-1,j-1,n,dp,m);
        
        int right=m[i][j]+solve(i-1,j+1,n,dp,m);
        
        return dp[i][j]=max({down,left,right});
        
        
    }

    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        
        vector<vector<int> > dp(N,vector<int> (N,-1));
        
        int maxi=0;
        int m=Matrix[0].size();
        for(int j=0;j<m;j++)
        {
            
        
        maxi=max(maxi,solve(N-1,j,m,dp,Matrix));
        } 
        
        return maxi;
    }
};
