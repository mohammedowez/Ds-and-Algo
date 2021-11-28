Using Merg sort 


Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).




class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    void merg(long long arr[],long long l, long long h,long long &cc)
    {
        
        long long m=(h+l)/2;
        long long i=l;
        long long j=m+1;
        long long  n=l+h-1;
        long long t[n];
        long long k=l;
        while(i<=m && j<=h)
        {
            if(arr[i]<=arr[j])
                t[k++]=arr[i++];
            else 
            {
                
                t[k++]=arr[j++];
                cc=cc+(m-i+1);
            }
        } 
        
        
        while(i<=m)
            t[k++]=arr[i++];
    
        
        while(j<=h)
            t[k++]=arr[j++];
        
        
        for(int i=l;i<=h;i++)
            arr[i]=t[i];
        
        
    }
    
    
    long long mergsort(long long arr[],long long l,long long h,long long &cc)
    {
    
        if(l<h)
        {
        long long mid=(h+l)/2;
         mergsort(arr,l,mid,cc);
        mergsort(arr,mid+1,h,cc);
         merg(arr,l,h,cc);
        }
        
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
       // ios_base::sync_with_stdio(0),cin.tie(0);
        
        long long cc=0;
        mergsort(arr,0,N-1,cc);
        
        return cc; 
    }

};
