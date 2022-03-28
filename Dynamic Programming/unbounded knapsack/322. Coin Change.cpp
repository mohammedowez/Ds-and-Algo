Example 1:

Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1
  
  class Solution {
public:
    int coinChange(vector<int>& coins, int sum) {
        int n= coins.size();
        vector<vector<int>> t(n+1, vector<int>(sum+1, -1));
        int res = helper(coins, n, sum, t);
        
        return (res==INT_MAX || res == INT_MAX-1) ? -1 : res;
    }
    
    int helper(vector<int>& coins, int n, int sum, vector<vector<int>>& t){
        if(n<=0) return INT_MAX-1;
        if(sum == 0) return 0;
        
        if(t[n][sum] != -1) return t[n][sum];
        
		//Unbounded Knapsack Code
        if(coins[n-1] <= sum) {
            t[n][sum] = min(1 + helper(coins, n, sum-coins[n-1], t), 
                            helper(coins, n-1, sum, t));
            
        }
        else{
            t[n][sum] = helper(coins, n-1, sum, t);
            
        }
        
        return t[n][sum];
    }
};
