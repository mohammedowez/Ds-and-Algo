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
  
