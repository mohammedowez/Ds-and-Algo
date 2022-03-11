#include <bits/stdc++.h>
using namespace std;



int solve(int n,vector<int> &v,vector<int> &dp)
{
	if(n==0)
		return 0;
		
	if(dp[n]!=-1)
		return dp[n];

	int right=INT_MAX;
	
	int	left=solve(n-1,v,dp)+abs(v[n]-v[n-1]);
	if(n>1)
		right=solve(n-2,v,dp)+abs(v[n]-v[n-2]);
	
	return dp[n]=min(left,right);
	
}
int main()
{
	vector<int> v{10,20,30,10};
	vector<int> dp(v.size()+1,-1);
	
	cout<<solve(v.size()-1,v,dp);
	
}
