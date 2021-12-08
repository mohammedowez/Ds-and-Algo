Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

  
  class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
     
        
        vector<int> res;
        
        int i=0,j=0;
        int n=nums.size();
        deque<int> dq;
        while(i<n)
        {
            
            while(dq.size()>0 &&  dq.back()<nums[i]) 
                dq.pop_back();
            
            
            dq.push_back(nums[i]);
            
            if(i-j+1<k)
                i++;
            else if(i-j+1==k)
            {
                res.push_back(dq.front());
                
                if(dq.front()==nums[j])
                    dq.pop_front();
                
                i++,j++;
            }
        } 
        return res;
        
    }
};
