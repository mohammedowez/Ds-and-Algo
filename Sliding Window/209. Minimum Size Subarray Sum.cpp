Example 1:

Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:

Input: target = 4, nums = [1,4,4]
Output: 1

  
  class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        //unordered_map<int,int> mp;
        int i=0,j=0;
        int maxLen=INT_MAX;
        int sum=0;
        
        while(i<nums.size())
        {
            
            sum=sum+nums[i];
            if(sum<target)
                i++;
            else 
            {
                
            
                while(sum>=target)
                {
                    maxLen=min(maxLen,i-j+1);
                    sum=sum-nums[j];
                    j++;
                } 
                i++;
            }
            
        } 
        
        return maxLen==INT_MAX?0:maxLen;
        
        
        
    }
};
