int dp[101][101];
int solve(int arr[],int i,int j)
{
    if(i==j)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    
    dp[i][j]=INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp=solve(arr,i,k) +solve(arr,k+1,j) +arr[i-1]*arr[j]*arr[k];
        
        if(temp<dp[i][j])
            dp[i][j]=temp;
    }
    return dp[i][j];
}
