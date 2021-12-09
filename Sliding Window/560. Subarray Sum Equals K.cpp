Example 1:

Input: nums = [1,1,1], k = 2
Output: 2

Example 2:

Input: nums = [1,2,3], k = 3
Output: 2


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        if(nums.size()==0)
            return 0;
       
        unordered_map<int,int> m;
        int c=0,s=0;
        
        for(int i=0;i<nums.size();i++)
        {
            s=s+nums[i];
            
            if(s==k)
                c++;
            if(m.find(s-k)!=m.end())
                c=c+m[s-k];
            
            m[s]++;
        }
        return c;
    }
};
