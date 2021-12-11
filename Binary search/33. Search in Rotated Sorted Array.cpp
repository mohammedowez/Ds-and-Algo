class Solution {
public:
    int search(vector<int>& nums, int tar) {
        
        int low=0;
        int high=nums.size()-1;
        
        while(low<=high)
        {
            int mid=(low+high)/2;
            
            if(nums[mid]==tar)
                return mid;
            
            else if(nums[mid]>=nums[low])
            {
                if(tar<=nums[mid] && tar>=nums[low])
                        high=mid-1;
                else 
                        low=mid+1;
                
            } 
            
            else 
            {
                if(tar>=nums[mid] && tar<=nums[high])
                    low=mid+1;
                else 
                    high=mid-1;
            }
            
             
        }
        
        return -1;
        
    }
};
