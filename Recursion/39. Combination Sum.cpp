// 1 appraocah

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
class Solution {
public:
    
    void solve(int i,vector<vector<int>> &ans,int t,vector<int> &v,         vector<int> &res)
    {
        
        if(t<0)
        {
            return ;
        }
            if(t==0)
            {
                
                ans.push_back(res);
            return;
            }
         
        
        for(;i<v.size();i++)
        {
            
    
            res.push_back(v[i]);
            solve(i,ans,t-v[i],v,res);
            res.pop_back();
        } 
        
    
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, 
                                       int target) 
    {
        
        
        vector<vector<int>> ans;
        
        if(candidates.size()==0)
            return ans;
        
        vector<int> res;
        solve(0,ans,target,candidates,res);
        
        return ans;
        
        
        
    }
};


// 2 appraoch

class Solution {
public:
    
    void solve(int i,vector<vector<int>> &ans,int t,vector<int> &v, vector<int> &res)
    {
        
        if(i==v.size())
        {
            if(t==0)
                ans.push_back(res);
            return;
        } 
        
        if(v[i]<=t)
        {
            res.push_back(v[i]);
            solve(i,ans,t-v[i],v,res);
            res.pop_back();
        } 
        
        solve(i+1,ans,t,v,res);
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, 
                                       int target) 
    {
        
        
        vector<vector<int>> ans;
        
        if(candidates.size()==0)
            return ans;
        
        vector<int> res;
        solve(0,ans,target,candidates,res);
        
        return ans;
        
        
        
    }
};


// 3 appraoch
class Solution {
public:
    
    
    void solve(int i,int t,int s,vector<int> v,vector<int> &f,
              vector<vector<int>> &ans)
    {
        
        if(s>t)
            return;
        
        if(s==t)
        {
            ans.push_back(v);
            return;
        } 
        
        for(;i<f.size();i++)
        {
            s=s+f[i];
            v.push_back(f[i]);
            solve(i,t,s,v,f,ans);
            
            s=s-f[i];
            v.pop_back();
            
        }
        
        
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, 
                                       int target) {
        ios_base::sync_with_stdio(0),cin.tie(0);
        
        
        
        int s=0;
        vector<int> v;
        vector<vector<int>> ans;
        
        if(candidates.size()==0)
            return ans;
        
        solve(0,target,s,v,candidates,ans);
        
        
        return ans;
    }
};


