Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

class Solution {
public:
    
    // time complexity is = O(nlogk)
    // space complexity is =O(k)
    
    
    int findKthLargest(vector<int>& nums, int k) {
        
        // create a min heap
        priority_queue<int,vector<int> > min_heap;
        
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            // push all the elements into the heap
            min_heap.push(nums[i]);
            
            // if the size is greater then the heap remove it 
            if(min_heap.size()>n-k+1)
                min_heap.pop();
        } 
        
        // return the min heap top element 
        return min_heap.top();
        
    }
};
