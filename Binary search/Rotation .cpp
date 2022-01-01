Input:
N = 5
Arr[] = {5, 1, 2, 3, 4}
Output: 1
Explanation: The given array is 5 1 2 3 4. 
The original sorted array is 1 2 3 4 5. 
We can see that the array was rotated 
1 times to the right.	


int findKRotation(int arr[], int n) {
	    // code here
	    
	    int low=0;
	    int high=n-1;
	    while(low<=high)
	    {
	        int mid=low+(high-low)/2;
	        
	        int next=(mid+1)%n;
	        int pre=(mid+n-1)%n;
	        
	        if(arr[mid]<=arr[pre] && arr[mid]<=arr[next])
	            return mid;
	            
	       else if(arr[mid]<arr[high])
	        high=mid-1;
	       else 
	        low=mid+1;
	    }
	    
    return 0;
    
	    
	}
