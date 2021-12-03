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

class Solution {
public:
    void solve(int o,int c,string op,vector<string> &v)
    {
        if(o==0 && c==0)
        {
            v.push_back(op);
            return;
        } 
        if(o!=0)
        {
            string op1=op;
            op1.push_back('(');
            solve(o-1,c,op1,v);
        } 
        
        if(c>o)
        {
            string op1=op;
            op1.push_back(')');
            solve(o,c-1,op1,v);
        }
        
    }
    
    vector<string> generateParenthesis(int n) 
    {
    
        vector<string> v;
        string op="";
        int open=n;
        int close =n;
        
        solve(open,close,op,v);
        
        return v;
        
    }
};
