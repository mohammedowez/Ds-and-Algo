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


vector<vector<int> > dp(1001,vector<int> (1001,0));
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else 
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        } 
        
        return dp[m][n];


// if u want to print the longest commom subsequence
#include <bits/stdc++.h>

using namespace std;

void lcs(string s1, string s2) {

  int n = s1.size();
  int m = s2.size();

  vector < vector < int >> dp(n + 1, vector < int > (m + 1, 0));
  for (int i = 0; i <= n; i++) {
    dp[i][0] = 0;
  }
  for (int i = 0; i <= m; i++) {
    dp[0][i] = 0;
  }

  for (int ind1 = 1; ind1 <= n; ind1++) {
    for (int ind2 = 1; ind2 <= m; ind2++) {
      if (s1[ind1 - 1] == s2[ind2 - 1])
        dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
      else
        dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
    }
  }

  int len = dp[n][m];
  int i = n;
  int j = m;

  string str(len,'$');
  
  int index=len-1;

  while (i > 0 && j > 0) {
    if (s1[i - 1] == s2[j - 1]) {
      str[index] = s1[i - 1];
      index--;
      i--;
      j--;
    } else if (s1[i - 1] > s2[j - 1]) {
      i--;
    } else j--;
  }
  cout << str;
}

int main() 
{

  string s1 = "abcdek";
  string s2 = "bdgek";

  cout << "The Longest Common Subsequence is ";
  lcs(s1, s2);
}
