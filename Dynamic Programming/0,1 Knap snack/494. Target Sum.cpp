Example 1:

Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


class Solution {
public:
    int dp[31][2002];
    int solve(vector<int>& nums,int sum,int t,int ind){
        int n=nums.size();
        if(n==ind){
            if(sum==t) return 1;
            return 0;
        }
        if(dp[ind][1000+sum]!=-1) return dp[ind][1000+sum];
        int res=0;
        res+=solve(nums,sum+nums[ind],t,ind+1);
        res+=solve(nums,sum-nums[ind],t,ind+1);
        return dp[ind][1000+sum] = res;
    }
    
    
    int findTargetSumWays(vector<int>& nums, int t) {
        memset(dp,-1,sizeof(dp));
        return solve(nums,0,t,0);
    }
};
