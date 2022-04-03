Input:
str = "axxxy"
Output: 2
Explanation:
The given array with indexes looks like
a x x x y 
0 1 2 3 4
  
  
  int  solve(int i,int j,string &str,vector<vector<int>> &dp)
	{
	    if(i==0 or j==0)
	        return 0;
	   
	   if(dp[i][j]!=-1)
	    return dp[i][j];
	    
	        
	    if(str[i-1]==str[j-1] and i!=j)
	    {
	        return dp[i][j]=1+solve(i-1,j-1,str,dp);     
	    } 
	    else 
	    {
	        return dp[i][j]=max(solve(i-1,j,str,dp),solve(i,j-1,str,dp));
	    }
	}
	
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n=str.size();
		    vector<vector<int> > dp(n+1,vector<int> (n+1,-1));
		    
		    return solve(n,n,str,dp);
		}
