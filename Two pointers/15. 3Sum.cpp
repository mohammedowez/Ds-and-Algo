Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:

Input: nums = []
Output: []


class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
         vector<vector<int>> res;
        if(nums.size()==0)
            return res;
        
            
        sort(nums.begin(),nums.end());
        
       
        
        for(int i=0;i<nums.size();i++)
        {
             if(i > 0 && nums[i]==nums[i-1])
                 continue;
            int left=i+1;
            int right=nums.size()-1;
            
            while(left<right)
            {
                
            if(nums[left]+nums[right]+nums[i]==0)
            {
                res.push_back({nums[left],nums[right],nums[i]});  
                
                while(left<right && nums[left]==nums[left+1])
                    left++;
                
                while(right>left && nums[right]==nums[right-1])
                    right--;
                
                left++;
                right--;
            }  
            else if(nums[left]+nums[right]+nums[i]<0)
                left++;
            else 
                right--;
            }
            
        }
        
     return res;   
    }
};
