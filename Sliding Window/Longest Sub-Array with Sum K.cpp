Example 1:
 

Input :
A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.

  
  class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { 
        // Complete the function
        
        int s=0,c=0;
        unordered_map<int,int> m;
        
        int ma=0;
        
        for(int i=0;i<n;i++)
        {
            s=s+a[i];
            
            if(s==k)
                ma=max(ma,i+1);
                
            if(m.find(s-k)!=m.end())
               ma=max(ma,i-m[s-k]);
            if(m.find(s)==m.end())
                m[s]=i;
        }
        return ma;
    } 

};
