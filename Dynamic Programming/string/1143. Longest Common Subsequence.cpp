class Solution {
public:
    
    int solve(int m,int n,string &s1,string &s2,vector<vector<int> > &dp)
    {
        if(m<0 or n<0)
            return 0;
        
        if(dp[m][n]!=-1)
            return dp[m][n];
        
        
        if(s1[m]==s2[n])
            return dp[m][n]=1+solve(m-1,n-1,s1,s2,dp);
        
        else 
            return dp[m][n]=max(solve(m-1,n,s1,s2,dp),solve(m,n-1,s1,s2,dp));
    
        
        //return dp[m][n];
        
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        
        int m=text1.size();
        int n=text2.size();
        
        vector<vector<int> > dp(1001,vector<int> (1001,-1));
        
        return solve(m-1,n-1,text1,text2,dp);
    }
};
