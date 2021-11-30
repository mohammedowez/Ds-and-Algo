Input:  N = 3
Output: 111 110 101
Explanation: 111, 110 and 101 have more 
than or equal 1's than 0's


class Solution{
public:	

    void solve(int one,int zero,int n,string op,vector<string> &v)
    {
        
        if(n==0)
        {
            v.push_back(op);
            return;
        } 
        
        if(one>=zero)
        {
            solve(one+1,zero,n-1,op+'1',v);
        } 
        
        if(zero<one)
        {
            solve(one,zero+1,n-1,op+'0',v);
        } 
        
        return ;
        
        
        
    }
    
	vector<string> NBitBinary(int N)
	{
	    // Your code goes here
	    
	    int one=0,zero=0;
	    string op="";
	    vector<string> v;
	    
	    solve(one,zero,N,op,v);
	    
	    return v;
	    
	}
};
