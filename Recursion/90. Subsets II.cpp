class Solution {
public:
    
    vector<vector<int>> res;
    set<vector<int>> s;
    
    void solve(vector<int> ip,int i,vector<int> op)
    {
        
        
        
        if(ip.size()==i)
        {
            if(s.find(op)==s.end())
            {
            s.insert(op); 
            res.push_back(op);
            }
            return;
        } 
        
       
        op.push_back(ip[i]);
        solve(ip,i+1,op); 
        
        op.pop_back();
        solve(ip,i+1,op);
        
        return;
        
        
    }
   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    
        if(nums.size()==0)
            return res;
        
        res.clear();
        
        vector<int> op;
        sort(nums.begin(),nums.end());
        
        solve(nums,0,op);
        //sort(res.begin(),res.end());
        return res;
        
    }
};
