vector<long long> nextGreaterToLeft(vector<long long> arr, int n)
    {
        // Your code here\\
        
        vector<long long > v(n);
        stack<long long > s;
        
        for(long long i=0;i<n;i++)
        {
            
            while(!s.empty() && arr[i]>s.top())
                    s.pop();
                    
            if(s.empty())
                v[i]=-1;
            
            else 
            {
                v[i]=s.top();
            } 
            
            s.push(arr[i]);
            
        } 
       
        return v;
    }
