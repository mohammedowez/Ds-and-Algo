Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167
  
  class Solution {
public:
    int dp[501][501];
    int solve(vector<int> &arr, int i, int j)
    {
        if(i >= j)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int ans = INT_MIN;
        for(int k = i; k < j; k++)
        {
            int temp_ans = solve(arr, i, k) + 
                solve(arr, k+1, j) + 
                (arr[i-1] * arr[k] * arr[j]);
            ans = max(ans, temp_ans);
        }
        
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) 
    {
        nums.push_back(1); //if i+1 goes out of bound so to avoid this add 1 
        nums.insert(nums.begin(), 1); //if i-1 goes out of bound so to avoid this add 1 
        memset(dp, -1, sizeof(dp));
        return solve(nums, 1, nums.size()-1);
    }
};
