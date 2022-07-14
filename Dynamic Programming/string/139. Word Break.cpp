Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.
Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false
  
  
  class Solution {
public:
    
    // time complxity is o(n^2)
    //else if dont use the dp then O(2^n)
    
    int dp[305];
    bool solve(string &s,unordered_set<string> &st,int ind)
    {
        if(ind==s.size())
        {
            return 1;
        } 
        
        if(dp[ind]!=-1)
            return dp[ind];
        
        for(int j=ind;j<s.size();j++)
        {
            if(st.count(s.substr(ind,j-ind+1)) and solve(s,st,j+1))
                return dp[ind]= 1;
            
        } 
        
        return dp[ind]=0;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        
        memset(dp,-1,sizeof(dp));
        
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        
        return solve(s,st,0);
    }
};
