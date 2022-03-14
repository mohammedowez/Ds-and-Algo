Example 2:

Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down


class Solution {
public:
    
    // Top to down
    int solve(int i,int j,vector<vector<int>> &dp)
    {
        if(i==0 and j==0)
            return 1;
        
        if(i<0 or j<0)
            return 0;
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int up=solve(i-1,j,dp);
        int left=solve(i,j-1,dp);
        
        return dp[i][j]=up+left;
        
    }
    
    int uniquePaths(int m, int n) {
       
       
        vector<vector<int>> dp(m,vector<int> (n,-1));
    
         // bottom to up
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 || j==0)
                {
                    

                    dp[i][j]=1;
                    continue;
                }
                else 
                {
                    int up=0,left=0;
                    if(i>0)
                        up=dp[i-1][j];
                    if(j>0)
                        left=dp[i][j-1];
                        
                    dp[i][j]=up+left;
                }
                
            }
        } 
        
        return dp[m-1][n-1];
        
        
    }
};
