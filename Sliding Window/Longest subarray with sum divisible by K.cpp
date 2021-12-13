Input:
A[] = {2, 7, 6, 1, 4, 5}
K = 3
Output: 4
Explanation:The subarray is {7, 6, 1, 4}
with sum 18, which is divisible by 3.


class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    // Complete the function
	   int s=0,c=0;
        unordered_map<int,int> mp;
        
        int ma=0;
        int rem=0;
        mp.insert({0,-1});
        
        for(int i=0;i<n;i++)
        {
            s=s+arr[i];
            rem=s%k;
                if(rem<0)
                    rem=rem+k;
            if(s%k==0)
                ma=max(ma,i+1);
                
            if(mp.find(rem)!=mp.end())
            {
                int ind=mp[rem];
            
               ma=max(ma,i-ind);
            } 
            else
            {
            
                mp[rem]=i;
            }
        }
        return ma;
	    
	}
};
