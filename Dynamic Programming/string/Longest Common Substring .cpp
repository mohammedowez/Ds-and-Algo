
Example 1:

Input: S1 = "ABCDGH", S2 = "ACDGHR"
Output: 4
Explanation: The longest common substring
is "CDGH" which has length 4

int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        
        vector<vector<int>> dp(1001,vector<int>(1001,0));
        
        int ans=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(S1[i-1]==S2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                } 
                else 
                dp[i][j]=0;
            }
        } 
        
        return ans;
    }
