class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size()==1)
            return nums[0];
        
        
        if(nums[0]<nums.back())
            return nums[0];
        
        int l=0;
        int h=nums.size()-1;
        int m=0;
        while(l<h)
        {
             m=l+(h-l)/2;
            //cout<<l<<" "<<h<<" "<<nums[m]<<"\n";
            if (nums[l] < nums[h]) 
                    return nums[l]; 

            // mid is larger than right - min is in right side
            else if (nums[m] > nums[h]) 
                l = m + 1;

            // mid is smaller than right - min is in left side (including mid)
            else h = m;
            
        } 
        
        return nums[l];
        
    }
};
