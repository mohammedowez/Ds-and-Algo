void immediateSmaller(int *arr, int n) {
	    //  code here
	    
	    vector<int> v(n);
	    stack<int> s;
	    
	    for(int i=n-1;i>=0;i--)
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
