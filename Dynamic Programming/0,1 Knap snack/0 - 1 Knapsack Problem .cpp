Example 1:

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3
Example 2:

Input:
N = 3
W = 3
values[] = {1,2,3}
weight[] = {4,5,6}
Output: 0


// solution 1 memoization 
int dp[1002][1002];
    
    int solve(int w,int wt[],int val[],int n)
    {
        if(n==0 or w==0)
       {
           return 0;
       } 
       
       
       if(dp[n][w]!=-1)
        return dp[n][w];
        
       if(wt[n-1]<=w)
       {
           return dp[n][w]=max(val[n-1]+solve(w-wt[n-1],wt,val,n-1),
                     solve(w,wt,val,n-1));
           
       } 
       else 
       {
          return dp[n][w]= solve(w,wt,val,n-1);
       }
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       
       memset(dp,-1,sizeof(dp));
       
       return solve(w,wt,val,n);
       
       //return dp[n][w];
       
    }
  
// iterative solution

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
       
       int dp[1002][1002];
       
       for(int i=0;i<n+1;i++)
       {
           for(int j=0;j<w+1;j++)
           {
               if(i==0 or j==0)
                dp[i][j]=0;
           }
       } 
       
       
       for(int i=1;i<n+1;i++)
       {
           for(int j=1;j<w+1;j++)
           {
               if(wt[i-1]<=j)
               {
                   dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
               } 
               else 
               {
                   dp[i][j]=dp[i-1][j];
               }
           }
       } 
       
       return dp[n][w];
       
    }
};
