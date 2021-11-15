#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(int *arr, int n) {
	    //  code here
	    
	    vector<int> v(n);
	    stack<int> s;
	    
	    for(int i=0;i<n;i++)
	    {
	        while(!s.empty() and arr[i]<s.top())
	            s.pop();
	           
	        if(s.empty())
	            v[i]=-1;
	       else 
	            v[i]=s.top();
	           
	       s.push(arr[i]);
	    } 
	    
	    for(int i=0;i<n;i++)
	    {
	        arr[i]=v[i];
	    }
	    
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends
