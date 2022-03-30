Example 1:

Input: n = 12
Output: 3
Explanation: 12 = 4 + 4 + 4.
Example 2:

Input: n = 13
Output: 2
Explanation: 13 = 4 + 9.
  
  
  class Solution {
public:
 /*   
    // refer this  ->https://leetcode.com/problems/perfect-squares/discuss/1520447/c%2B%2B-dp-easy-to-understand
  
    
   Time complexity: O(n*sqrt(n)) outer loop is of sqrt(n) iterations and in the inner loop <n iterations roughly.

Space Complexity: O(n).
*/
    
    
    int numSquares(int n) {
        
        
        //vector for updating the dp array/values
        vector<int> dp(n+1,INT_MAX);
        //base case
        dp[0]=0;
        int count = 1;
        while(count*count <= n) {
        int sq = count*count;
        for(int i = sq; i < n+1; i++) {
            dp[i] = min(dp[i-sq] + 1,dp[i]);
        }
        count++;
    }
    return dp[n];
    }
};
