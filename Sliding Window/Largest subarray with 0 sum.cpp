Input:
N = 8
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with
sum 0 will be -2 2 -8 1 7.
  
  
  int maxLen(vector<int>&a, int n)
    {   
        // Your code here
      //  ios_base::sync_with_stdio(0),cin.tie(0);
        
        
        unordered_map<int,int> mp;
        
        int maxi=0;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum=sum+a[i];
            if(sum==0)
                maxi=max(maxi,i);
                
            if(mp.find(sum)!=mp.end())
            {
                maxi=max(i-mp[sum],maxi);
            } 
            else
                mp[sum]=i;
            
        } 
        
        return maxi;
        
    }
