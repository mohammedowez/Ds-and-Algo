Example 1:

Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Example 2:

Input: nums = [2,3]
Output: [2,3]



class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums)
    {
        // by two pointers
        ios_base::sync_with_stdio(0),cin.tie(0);
        
        int i=0,j=1;
        
        while(i<nums.size() && j<nums.size())
        {
            if(nums[i]%2==0)
                i=i+2;
            else if(nums[j]%2==1)
                j=j+2;
            else 
                swap(nums[i],nums[j]);
        } 
        
        return nums;
            
    }
};
