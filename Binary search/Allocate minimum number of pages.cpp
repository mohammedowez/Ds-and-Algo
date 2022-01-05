Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:113
Explanation:Allocation can be done in 
following ways:{12} and {34, 67, 90} 
Maximum Pages = 191{12, 34} and {67, 90} 
Maximum Pages = 157{12, 34, 67} and {90} 
Maximum Pages =113. Therefore, the minimum 
of these cases is 113, which is selected 
as the output.

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
   bool isvalid(int A[],int n,int k,int max)
    {
        int sum=0,student=1;
        for(int i=0;i<n;i++)
        {
            sum=sum+A[i];
            if(sum>max)
            {
                student++;
                sum=A[i];
            }
            if(student >k)
            return false;
            
            
        }
        return true;
    
    }
    
    int findPages(int A[], int N, int M) 
    {
        //code here
        
        int maxi=*max_element(A,A+N);
      //  cout<<maxi;
        int sum=accumulate(A,A+N,0);
        //cout<<sum;
        int l=maxi;
        int h=sum;
        int res=-1;
        while(l<=h)
        {
            int m=l+(h-l)/2;
            if(isvalid(A,N,M,m))
            {
                res=m;
                h=m-1;
            } 
            else
                l=m+1;
            
        } 
        
        return res;
        
    }
};
