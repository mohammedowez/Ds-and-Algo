Example 2:

Input: N = 4, W = 8
val[] = {1, 4, 5, 7}
wt[] = {1, 3, 4, 5}
Output: 11
Explanation: The optimal choice is to 
pick the 2nd and 4th element.


class Solution{
public:

int solve(int wt[],int val[],int n,int w,vector<vector<int> > &dp)
  {
      
      if(w<0)
      {
          return 0;
      }
      
      if(n<0||w==0)
        {
            return 0;
        }
      
      if(dp[n][w]!=-1)
             return dp[n][w];
             
             
        int notTake=solve(wt,val,n-1,w,dp);
        
        int take =INT_MIN;
        if(wt[n]<=w)
            take=val[n]+solve(wt,val,n,w-wt[n],dp);
            
        return dp[n][w]=max(take,notTake);
        
             
  }
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        
         vector<vector<int> > dp(N+1,vector<int> (W+1,-1));
        
       
        
        return solve(wt,val,N-1,W,dp);
    }
};
