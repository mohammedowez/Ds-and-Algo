Example 1:

Input: nums = [1,3,5]
Output: 1

Example 2:

Input: nums = [2,2,2,0,1]
Output: 0

  
  class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums[0]<nums.back())
            return nums[0];
        
        int l=0;
        int h=nums.size()-1;
        while(l<h)
        {
            int m=l+((h-l))/2;
            if(nums[l]<nums[h])
                return nums[l];
            else if(nums[m]>nums[h])
                l=m+1;
            else 
                h--;
        } 
        
        return nums[l];
    }
};

  
  class Solution {
public:
    int findMin(vector<int>& nums) {
        int n= nums.size();
        int low=0;
        int high=n-1;
        int ans=INT_MAX;
        while(low<=high){
            int mid = low+(high-low)/2;
            
            if(nums[mid]==nums[low] && nums[mid]==nums[high]){
                ans=min(ans,nums[mid]);
                low++;
                high--;
                continue;
            }
            
            
            if(nums[low]<= nums[mid])
            {
                ans= min(ans,nums[low]);
                low=mid+1;
            }
            else
            {
                ans =min(ans,nums[mid]);
                high=mid-1;
            }
            
            
        }
        return ans;
    }
};
