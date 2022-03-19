Example 1:

Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].
Example 2:

Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.


// recursion top down appraoch with memoization

class Solution {
public:
    
    
    int solve(int n,vector<int> &v,int tar,vector<vector<int>> &dp)
    {
        if(tar==0)
            return 1;
        
        if(n==0)
        {
            if(tar==v[0])
                return 1;
            return 0;
        }
        
        if(dp[n][tar]!=-1)
            return dp[n][tar];
        
        
        int NotTake=solve(n-1,v,tar,dp);
        
        int take=0;
        if(v[n]<=tar)
            take=solve(n-1,v,tar-v[n],dp);
        
        return dp[n][tar]=NotTake or take;
            
    }
    bool canPartition(vector<int>& nums) {
        
        
        int sum=0;
        for(int i: nums)
            sum+=i;
        
        if(sum%2!=0)
            return 0;
        
        vector<vector<int>> dp(nums.size(),vector<int> (sum+1,-1));
        
        if(solve(nums.size()-1,nums,sum/2,dp))
            return 1;
        return 0;
        
        
    }
};
