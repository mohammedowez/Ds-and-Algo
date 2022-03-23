Input:
N = 6
arr[] = {3, 34, 4, 12, 5, 2}
sum = 9
Output: 1 
Explanation: Here there exists a subset with
sum = 9, 4+3+2 = 9.

class Solution{   
public:
    
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
};




class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        
        int n=arr.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
        
        
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<sum+1;j++)
            {
                if(i==0)
                    dp[i][j]=0;
                if(j==0)
                    dp[i][j]=1;
                
            }
        } 
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<sum+1;j++)
            {
                if(arr[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
                } 
                else if(arr[i-1]>j)
                    dp[i][j]=dp[i-1][j];
            }
        } 
        
        return dp[n][sum];
    }
};
