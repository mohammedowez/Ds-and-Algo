Example 1:

Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
  
  class Solution {
public:
    
    int solve(vector<int>&prices, int day, int transactionsLeft, vector<vector<int>> &Memo)
    {
        
        if(day == prices.size()){
            return 0;
        }
        
        if(transactionsLeft == 0){
            return 0;
        }
        
        
        
        if(Memo[day][transactionsLeft] != -1){ // if problem has already been solved 
            return Memo[day][transactionsLeft];
        }
        
        // choice 1
        // no transaction today
        int ans1 = solve(prices, day + 1, transactionsLeft, Memo);
        
        
        // choice 2
        // doing the possible transaction today     
        int ans2 = 0;
        bool buy = (transactionsLeft % 2 == 0);
        
        if(buy == true)
        { // buy
            ans2 = -prices[day] + solve(prices, day + 1, 
                                        transactionsLeft - 1, Memo);
        }else
        { // sell
            ans2 = prices[day] + solve(prices, day + 1, 
                                       transactionsLeft - 1, Memo);
        }
        
        return Memo[day][transactionsLeft] = max(ans1, ans2); // store ans in memo before 
        
        
    }
    
    
    int maxProfit(vector<int>& prices) {
        
        vector<vector<int>> Memo(prices.size(), vector<int>(5, -1));
        int ans = solve(prices, 0, 4, Memo);
        return ans;
        
    }
};
