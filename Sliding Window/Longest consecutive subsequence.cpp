Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:

Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size()==0)
            return 0;
       
        sort(nums.begin(),nums.end());
        int cnt=1;
        int maxi=0;
        
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
                continue;
            else if(nums[i]==nums[i-1]+1)
                cnt++;
            else 
            {
                maxi=max(maxi,cnt);
                cnt=1;
            }
        }
        
        return max(maxi,cnt);
        
    }
};
