Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit

class Solution {
public:
    int numDistinct(string s, string t) {
	static int MOD = (int)1e9 + 7;            // To avoid Integer Overflow on some cases
        
	int n = s.size(), m = t.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        // fill the base condition to match all the string in a container
	for(int i=0; i<n; i++) dp[i][0] = 1;

	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=m; j++)
		{
			if(s[i-1] == t[j-1])
				dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % MOD;
			else 
				dp[i][j] = dp[i-1][j];
		}
	}

	return dp[n][m];
}
};
