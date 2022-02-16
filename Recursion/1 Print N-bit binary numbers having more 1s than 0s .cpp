void solve(vector<string> &v,int one,int zero,int n,string s)
    {
        if(one<zero)
            return;
        
        if(n==one+zero)
        {
            v.push_back(s);
            return;
        } 
        
        
        solve(v,one+1,zero,n,s+'1');
        
        
     
        solve(v,one,zero+1,n,s+'0');
        
        
        
        
    }
