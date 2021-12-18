Example 1:

Input:
N = 5, S = 12
A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements 
from 2nd position to 4th position 
is 12.

vector<int> subarraySum(int arr[], int n, long long s)
    {
        // Your code here
        
      //  sort(arr,arr+n);
        
        int i=0,j=0;
        int cs=0;
        while(i<n)
        {
            cs=cs+arr[i];
            if(cs<s)
                i++;
            else if(cs==s)
            {
                return {j+1,i+1};
            } 
            else if(cs>s)
            {
                while(cs>s)
                {
                    cs=cs-arr[j];
                    j++;
                } 
                
                if(cs==s)
                {
                    return {j+1,i+1};
                }
                i++;
            }
            
        } 
        return {-1};
        
        
    }
