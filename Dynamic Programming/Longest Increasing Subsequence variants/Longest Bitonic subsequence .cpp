Example 2:

Input: nums = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence 
{1, 2, 10, 4, 2, 1} has length 6.

int LongestBitonicSequence(vector<int>nums)
	{
	    // code here
	    
	    // this is very much similar to the  longest incresing subsequence 
	    
	    int n=nums.size();
	    vector<int> dp1(n,1);
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int pre=0;pre<i;pre++)
	        {
	            if(nums[pre]<nums[i] and dp1[pre]+1>dp1[i])
	                dp1[i]=1+dp1[pre];
	        } 
	        
	    } 
	    
	     // this is very much similar to the  longest Decreasing  subsequence 
	    vector<int> dp2(n,1);
	    
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int pre=n-1;pre>=i;pre--)
	        {
	            if(nums[pre]<nums[i] and dp2[pre]+1>dp2[i])
	                dp2[i]=1+dp2[pre];
	        } 
	        
	    }  
	    
	    int maxi=0;
	    for(int i=0;i<n;i++)
	    {
	        maxi=max(maxi,dp1[i]+dp2[i]-1);
	        
	    } 
	    
	    return maxi;
	    
	    
	    
	}
