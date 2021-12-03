Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

class Solution {
public:
    void solve(int o,int c,string op,vector<string> &v,int n)
    {
        if(op.size()==2*n)
        {
            v.push_back(op);
            return;
        } 
        
        if(o<n)
            solve(o+1,c,op+'(',v,n);
        if(c<o)
            solve(o,c+1,op+')',v,n);
        return;
        
    }
    
    vector<string> generateParenthesis(int n) 
    {
    
        vector<string> v;
        string op="";
        int open=n;
        int close =n;
        
        solve(0,0,op,v,n);
        
        return v;
        
    }
};
