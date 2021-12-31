Example 1:

Input:
N = 7, X = 2
Arr[] = {1, 1, 2, 2, 2, 2, 3}
Output: 4
Explanation: 2 occurs 4 times in the
given array.
  
  class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    
	    int l=0,h=n;
	    int f=-1;
	    while(l<=h)
	    {
	        int m=l+(h-l)/2;
	        if(arr[m]==x)
	        {
	            f=m;
	            h=m-1;
	        } 
	        else if(arr[m]>x)
	        {
	            h=m-1;
	        } 
	        else
	            l=m+1;
	    }
	    int la=-1;
	    l=0;
	    h=n;
	     while(l<=h)
	    {
	        int m=l+(h-l)/2;
	        if(arr[m]==x)
	        {
	            la=m;
	            l=m+1;
	        } 
	        else if(arr[m]>x)
	        {
	            h=m-1;
	        } 
	        else
	            l=m+1;
	    }
	    if(la!=-1 and f!=-1)
	        return (la-f+1);
	   return 0;
	    
	    
	}
};
