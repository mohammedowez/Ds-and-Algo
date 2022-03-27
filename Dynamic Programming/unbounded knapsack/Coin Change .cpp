Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}


class Solution 
{
  public:
    
    long long  int solve(int s[],int n,int m,vector<vector<long long int >>   &dp)
    {
        if(m==0)
            return 1;
            
        if(n==0)
        {
              if(m%s[0]==0) 
                return 1;
            else 
                return 0;
        } 
        
        if(dp[n][m]!=-1)
            return dp[n][m];
        
        long long  notTake=solve(s,n-1,m,dp);
        
        long long  take=0;
        if(s[n]<=m)
            take=solve(s,n,m-s[n],dp);
            
        return dp[n][m]=take+notTake;
        
    }
  
    long long int count(int S[], int n, int x) 
    {
        
        
         vector<vector<long long int >>dp(n,vector<long long int>(x+1,-1));
       
        
        return solve(S,n-1,x,dp);
        // code here.
    }
  
  
};
