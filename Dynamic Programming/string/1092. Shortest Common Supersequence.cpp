Example 1:

Input: str1 = "abac", str2 = "cab"
Output: "cabac"
Explanation: 
str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
The answer provided is the shortest such string that satisfies these properties.
  
  class Solution {
public:
    
    // use print LCS 
    string shortestCommonSupersequence(string str1, string str2) {
        
        string res="";
        
        vector<vector<int> > dp(1001,vector<int> (1001,0));
        
        int n=str1.size();
        int m=str2.size();
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(str1[i-1]==str2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        } 
        
        
        int i=n,j=m;
        
        while(i>0 and j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                res+=str1[i-1];
                i--;
                j--;
            } 
            else if(dp[i-1][j]>dp[i][j-1]) 
            {
                // going up word direction by taking the ith row element 
                res+=str1[i-1];
                i--;
            } 
            else 
            {
                // going right direction by taking the ith column element
                res+=str2[j-1];
                j--;
            }
        } 
        
        while(i>0)
        {
            res+=str1[i-1];
            i--;
        }
        
        while(j>0)
        {
            res+=str2[j-1];
            j--;
        } 
        
        cout<<res<<" \n";
        reverse(res.begin(),res.end());
         cout<<res<<" ";
        return res;
    }
};
