class Solution {
public:
    
    
    // Recursion -->top Down 
    // Time complexity is O(n*m)
    // Space complexity is O(n*m)
    
    int solve(int n,int m, vector<vector<int>> o, vector<vector<int>> &dp)
    {
        
        if(m<0 or n<0 or o[n][m]) 
            return 0;
        
        if(m==0 and n==0)
        {
            
            return 1;
        }
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        
            
        int up=solve(n-1,m,o,dp);
        int left=solve(n,m-1,o,dp);
            
        return dp[n][m]=left+up;
       
        
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& o) {
        
        int n=o.size();
        int m=o[0].size();
        
        
        vector<vector<int>> dp(n,vector<int> (m,0));
        
        //return solve(n-1,m-1,o,dp);
        
        
        // Bottom to up 
        // Tablulation 
        
        
        for(int i=0;i<n;i++)
        {
            if(o[i][0])
            {
                break;
            } 
            else
                dp[i][0]=1;
        } 
        
        
        for(int i=0;i<m;i++)
        {
            if(o[0][i])
            {
                break;
            } 
            else
                dp[0][i]=1;
        } 
        
        
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(o[i][j])
                    dp[i][j]=0;
                else 
                {
                    dp[i][j]=dp[i-1][j] +dp[i][j-1];
                }
            } 
        } 
        
        return dp[n-1][m-1];
        
    }
};
