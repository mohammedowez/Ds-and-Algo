class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        if(nums.size()==0 or k==0)
            return 0;
        
        int p=1;
        int c=0;
        int j=0,i=0;
        int n=nums.size();
        
        while(i<n)
        {
            p=p*nums[i];
            
            while(p>=k && j<i)
            {
                p=p/(nums[j]);
                j++;
            }
            if(p<k)
            {
                c=c+i-j+1;
            }   
            i++;
        } 
        
        return c;
    }
};
