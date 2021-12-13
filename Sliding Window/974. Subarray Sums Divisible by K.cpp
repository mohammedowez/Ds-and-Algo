Example 1:

Input: nums = [4,5,0,-2,-3,1], k = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]


class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        
        unordered_map<int,int> mp;
        int rem=0;
        int sum=0;
        int maxi=0;
        mp[0]=1;
        
        
        for(int i=0;i<nums.size();i++)
        {
            sum=sum+nums[i];
            rem=sum%k;
            
            if(rem<0)
                rem=rem+k;
            

            if(mp.find(rem)!=mp.end())
            {
               
                maxi=maxi+mp[rem];
            } 
           
            mp[rem]++;
            
        } 
        
        return maxi;
    }
};
