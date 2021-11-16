 long long getMaxArea(long long heights[], int n)
    {
        // Your code here
        
        
        vector<long long> nsl(n,0);
        stack <pair<long long,long long> > s1;
        
        for(long long i=0;i<n;i++)
        {
            
            while(!s1.empty() and (s1.top().first>=heights[i]))
                s1.pop(); 
            
            
            nsl[i]=(s1.empty())? -1:s1.top().second;
             
            
            s1.push({heights[i],i});
        }
        
        vector<long long> nsr(n,0);
        stack<pair<long long,long long>> s2;
        
        for(long long i=n-1;i>=0;i--)
        {
            while(!s2.empty() && heights[i]<=s2.top().first)
                s2.pop();
            
            if(s2.empty())
                nsr[i]=n;
            else 
                nsr[i]=s2.top().second;
            
            s2.push({heights[i],i});
            
        }
        
        vector<long long> w(n,0);
        for(long long i=0;i<n;i++)
        {
            w[i]=nsr[i]-nsl[i]-1;
        } 
        
        long long ma=0;
        for(long long i=0;i<n;i++)
        {
            ma=max(ma,heights[i]*w[i]);
        } 
        
        
        return ma;
        
        
    }
