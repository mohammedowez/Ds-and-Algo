Input:
N = 4, K = 4
Arr = [100, 200, 300, 400]
Output:
1000
Explanation:
Arr1 + Arr2 + Arr3  
+ Arr4 =1000,
which is maximum.

int maximumSumSubarray(int k, vector<int> &arr , int N){
        // code here 
        
        int i=0,j=0;
        int sum=0;
        
        int ma=0;
        while(i<N)
        {
            sum=sum+arr[i];
            if(i-j+1<k)
            {
                i++;
            } 
            else if(i-j+1==k)
            {
                ma=max(ma,sum);
                sum=sum-arr[j];
                j++;
                i++;
            } 
        } 
        
        return ma;
    }
    
    
    
    

class Solution{   
public:
    int maximumSumSubarray(int K, vector<int> &a , int N){
        
// sliding window 
        int s=0;
       for(int i=0;i<K;i++)
        s=s+a[i];
        
        int maxi=s;
        
        for(int i=K;i<N;i++)
        {
            s=s+a[i]-a[i-K];
            maxi=max(s,maxi);
        }
        
        return maxi;
        
        // code here 
    }
};



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
