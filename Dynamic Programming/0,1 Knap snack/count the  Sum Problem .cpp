Input: N = 6, arr[] = {2, 3, 5, 6, 8, 10}
       sum = 10
Output: 3
Explanation: {2, 3, 5}, {2, 8}, {10}


class Solution{
public :
	#define mod 1000000007
int helper(int n , int arr[], int sum, vector<vector<int>> &dp)
{
    if(n == 0 and sum != 0) 
        return 0;
    if(n == 0 and sum == 0) 
        return 1;
   
   if(dp[n][sum] != -1)
   return dp[n][sum];
   
   if(arr[n-1] <= sum)
   {
        dp[n][sum] = (helper(n-1,arr,sum-arr[n-1],dp)%mod + helper(n-1,arr,sum,dp)%mod);
   }
   else
   {
        dp[n][sum] = helper(n-1,arr,sum,dp)%mod;
   }
   return dp[n][sum]%mod;
   
}
   
int perfectSum(int arr[], int N, int sum)
{
       // Your code goes here
        // code here 
       vector<vector<int> > dp(N+1,vector<int> (sum+1,-1));
       
       return helper(N,arr,sum,dp);
}
};
