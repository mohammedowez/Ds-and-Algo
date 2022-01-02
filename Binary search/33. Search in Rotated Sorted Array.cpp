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



class Solution {
public:
    int bs(vector<int>&a,int k,int l,int r){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[mid]==k)
                return mid;
            else if(a[mid]<k)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    int rot_index(vector<int>&a,int l,int r,int n){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(a[mid]>a[n-1]&&a[mid+1]<=a[n-1])
                return mid;
            else if(a[mid]<a[n-1])
                r=mid-1;
            else
                l=mid+1; 
        }
      return -1;  
    }
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        if(nums.size()==0)
            return -1;
        if(nums[n-1]>nums[0])
            return bs(nums,target,0,n-1);
        else{
            int index=rot_index(nums,0,n-1,n);
            if(target>nums[n-1])
                return bs(nums,target,0,index);
            else
                return bs(nums,target,index+1,n-1);
        }
       return -1; 
    }
};
