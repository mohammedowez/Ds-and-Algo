// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &a , int N){
        
// sliding window 
        int s=0;
        int start=0,end=0;
        int maxi=0;
        while(start<N)
        {
            s=s+a[start];
            if(start-end+1<K)
                start++;
            else if(start-end+1==K)
            {
                maxi=max(maxi,s);
                s=s-a[end];
                start++;
                end++;
            }
            
        }
        
        return maxi;
        
        // code here 
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
} 
