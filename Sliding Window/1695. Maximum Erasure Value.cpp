Example 1:

Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].

Example 2:

Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].

  
  class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        ios_base::sync_with_stdio(0),cin.tie(0);
        
        set<int> st;
        
        int i=0,j=0;
        int maxlen=0;
        int ma=0;
        
        while(i<nums.size())
        {
            if(st.count(nums[i])==0)
            {
                st.insert(nums[i]);
                maxlen=maxlen+nums[i];
                ma=max(ma,maxlen);
                i++;
            } 
            else 
            {
                maxlen=maxlen-nums[j];
                st.erase(nums[j]);
                j++;
                
            }
            
        } 
        return ma;
        
    }
};

// Another solution
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
         int i=0,j=0,sum=0;
        unordered_map<int,int> mp;
        int maxi=0;
        
        
        while(i<nums.size())
        {
            if(mp[nums[i]]==0)
            {
                mp[nums[i]]++;
                sum=sum+nums[i];
                
                maxi=max(maxi,sum);
                i++;
            } 
            else
            {
                mp[nums[j]]--;
                sum=sum-nums[j];
                j++;
            }
               
        } 
        return maxi;
    }
};
