Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.
  
  
  int solve(int n,vector<int> &arr,int sum, vector<vector<int>> &dp)
    {
        if(sum==0)
            return 1;
            
        if(n==0)
        {
            if(arr[0]==sum)
                return 1;
            return 0;
        }  
        
        if(dp[n][sum]!=-1)
            return dp[n][sum];
        
        int NotTake=solve(n-1,arr,sum,dp);
        
        bool take=false;
        
        if(sum>=arr[n])
        {
            take=solve(n-1,arr,sum-arr[n],dp);
        } 
        
        return dp[n][sum]=NotTake or take; 
    }
    
    
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        vector<vector<int> > dp(arr.size(),vector<int> (sum+1,-1));
        
        return solve(arr.size()-1,arr,sum,dp);
        
    }
