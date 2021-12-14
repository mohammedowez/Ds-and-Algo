Example 1:

Input: nums = [1,1,1,0,0,0,1,1,1,1,0], k = 2
Output: 6
Explanation: [1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1. The longest subarray is underlined.
 
  
  class Solution 
{
public:
    int longestOnes(vector<int>& nums, int k) {
        
        
        int c=0,i=0,j=0;
        int maxi=0;
        
        for( i=0;i<nums.size();i++)
        {
           if(nums[i]==0)
           {
               c++;
           } 
            
            while(c>k)
            {
                
                if(nums[j]==0)
                    c--;
                j++;
            }
             
            maxi=max(maxi,i-j+1);
        } 
         
        
        return maxi;
        
        
    }
};
