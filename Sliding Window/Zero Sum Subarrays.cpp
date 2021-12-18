n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

ll findSubarray(vector<ll> arr, int n ) {
        //code here
        //ios_base::sync_with_stdio(false),cin.tie(NULL);
        
        unordered_map<int,int> mp;
        int s=0;
        int maxi=0;
        
        for(int i=0;i<n;i++)
        {
            s=s+arr[i];
            if(s==0)
            {
                maxi++;
            } 
            if(mp.find(s)!=mp.end())
            {
                maxi=maxi+mp[s];
                cout<<i<<" "<<maxi<<" "<<mp[s]<<"\n";
            }
            mp[s]++;
        } 
        
        return maxi;
        
    }
