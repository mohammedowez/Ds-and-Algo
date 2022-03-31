class Solution {
public:
    int minDistance(string word1, string word2) {
      
        vector<vector<int>> dp(501,vector<int> (501,0));
        
        int n=word1.size();
        int m=word2.size();
        for(int i=1;i<=word1.size();i++)
        {
            for(int j=1;j<=word2.size();j++)
            {
                if(word1[i-1]==word2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            } 
        } 
        int maxi=dp[n][m];
        
        return (abs(maxi-n)+abs(maxi-m));
    }
};
