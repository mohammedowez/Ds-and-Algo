Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]


class Solution {

    int firstpos(vector<int> nums,int key)
{
    int start=0;
    int end=nums.size()-1;
    
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;
        if(nums[mid]==key)
        {
            ans=mid;
            end=mid-1;
        }
        else if(nums[mid]>key)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
        
    }
    return ans;
}

int lastpos(vector<int> nums,int key)
{
    int start=0;
    int end=nums.size()-1;
   
    int ans=-1;
    while(start<=end)
    {
        int mid=start+(end-start)/2;;
        if(nums[mid]==key)
        {
            ans=mid;
            start=mid+1;
        }
        else if(nums[mid]<key)
        {
          start=mid+1;   
        }
        else
        {
            end=mid-1;
        }
        
    }
    return ans;
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       vector<int> arr;
        int startindex=firstpos(nums,target);
        //cout<<startindex;
        int lastindex=lastpos(nums,target);
        //cout<<lastindex;
        arr.push_back(startindex);
        arr.push_back(lastindex);
        return arr;
    }
};
