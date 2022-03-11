
Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.


class Solution {
public:
    
    int robHelper(vector<int>&nums, int i,vector<int> &dp){
        if(i>=nums.size()){
            return 0;
        }
        
        if(dp[i]!=-1)
                return dp[i];
        
        int Take = robHelper(nums, i+2,dp) + nums[i];
        int NotTake = robHelper(nums, i+1,dp);
        return dp[i]=max(Take,NotTake);
    }
    
    
    int rob(vector<int>& nums){
        
        vector<int> dp(nums.size(),-1);
        
        return robHelper(nums,0,dp);
    }
};
