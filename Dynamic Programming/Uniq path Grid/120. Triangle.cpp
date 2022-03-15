class Solution {
public:
    
    int solve(int i,int j,int n,int m, vector<vector<int>> &t,
              vector<vector<int>> &dp)
    {
        
        if(i==n-1)
        {
            return t[i][j];
            
        }
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int down=t[i][j]+solve(i+1,j,n,m,t,dp);
        
        int diagonal=t[i][j]+solve(i+1,j+1,n,m,t,dp);
        
        return dp[i][j]=min(down,diagonal);
         
    }
    
    
    
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int n=triangle.size();
        int m=triangle[0].size();
        
        vector<vector<int>> dp(n,vector<int> (n,-1));
        
       // return solve(0,0,n,m,triangle,dp);
        
        
        for(int j=0;j<n;j++)
            dp[n-1][j]=triangle[n-1][j];
        
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=i;j>=0;j--)
            {
                int down = triangle[i][j]+dp[i+1][j];
            int diagonal = triangle[i][j]+dp[i+1][j+1];
            
                  dp[i][j] = min(down, diagonal);
            }
        } 
        
        return dp[0][0];
        
    }
};
