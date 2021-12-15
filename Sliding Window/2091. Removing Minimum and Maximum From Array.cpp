Example 1:

Input: nums = [2,10,7,5,4,1,8,6]
Output: 5
Explanation: 
The minimum element in the array is nums[5], which is 1.
The maximum element in the array is nums[1], which is 10.
We can remove both the minimum and maximum by removing 2 elements from the front and 3 elements from the back.
This results in 2 + 3 = 5 deletions, which is the minimum number possible.

  
  
  			   (i)             (j)
   [ _ _ _ _ _ min _ _ _ _ _ _ max _ _ _ _ _ _ ] 
     <-- a -->      <-- b -->       <-- c -->
    <------------------- n ------------------->
   Here, 
   -> a : distance of minimum element from starting
   -> b : distance between minimum and maximum element 
   -> c : distance between maximum element from ending
   -> n : length of array

   Now lets look at different cases that we thought of,

   Case 1 : No. of deletion = (a + c) = ((i+1) + (n-j)),
   Case 2 : No. of deletion = (a + b) = (j+1)
   Case 3 : No. of deletion = (b + c) = (n - i)
   

class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int i = min_element(nums.begin() , nums.end()) - nums.begin();
        int j = max_element(nums.begin() , nums.end()) - nums.begin();
        
		//to make sure j points to greater index
        if(i>j) swap(i,j);
        
       // cout<<i<<j;
        return min( {j+1 , n-i , i+1+n-j });
    }
};
