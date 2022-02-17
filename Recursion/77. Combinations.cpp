class Solution {
public:
    
    
    vector<vector<int>> res;
    vector<int> v;
    
    void solve(int n,int k,int ind,int m)
    {
       
        
        if(v.size()==k)
        {
            
                res.push_back(v);
            return;
        } 
        
        for(int i=ind;i<n+1;i++)
        {
            
            v.push_back(i);
            solve(n,k,i+1,m);
            v.pop_back();
             
        }
        
    }
    
    
    
    
    vector<vector<int>> combine(int n, int k) {
    
        
        
        
        
        
        res.clear();
        int m=0;
        solve(n,k,1,m);
        
        
        return res;
        
    }
};

// 2 solution 
/*
class Solution 
{
public:
    void helper(vector<vector<int>>&v,vector<int>&aux,int index,int n,int k)
    {
        if(aux.size()==k)
        {
            v.push_back(aux);
            return;
        }
        if(index==n+1)
        {
            return;
        }
        aux.push_back(index);
        helper(v,aux,index+1,n,k);
        aux.pop_back();
        helper(v,aux,index+1,n,k);
    }
    vector<vector<int>>combine(int n, int k)
    {
        vector<vector<int>>v;
        vector<int>aux;
        helper(v,aux,1,n,k);
        return v;
    }
};*/
