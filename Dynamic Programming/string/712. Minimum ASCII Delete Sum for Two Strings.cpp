class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        
        
        int sum=0;
        for(int i=0;i<s1.size();i++)
            sum+=s1[i];
        
      //  cout<<sum<<"\n";
        for(int i=0;i<s2.size();i++)
            sum+=s2[i];
        
        //cout<<sum<<"\n";
        
        vector<vector<int>> dp(1001,vector<int> (1001,0));
        
        int n=s1.size();
        int m=s2.size();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=int(s1[i-1])+dp[i-1][j-1];
                
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]); 
            }
        } 
      // cout<<dp[n][m];
        
        int ans=dp[n][m];
        
        return (sum-2*ans);
        
        
    }
};
