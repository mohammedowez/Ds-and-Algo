class Solution {
public:
    
    vector<vector<int>> v;
    vector<int> res;
    
    void solve(vector<int> &nums,int l,int h)
    {
        if(l==h)
        {
            v.push_back(nums);
            return;
        } 
        
        for(int i=l;i<=h;i++)
        {
            swap(nums[l],nums[i]);
            solve(nums,l+1,h);
            swap(nums[l],nums[i]);
            
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.size()==0)
            return v;
        v.clear();
        
        
        solve(nums,0,nums.size()-1);
        
        return v;
        
        
        
    }
};


// 2 another 

class Solution {
public:
    
    vector<vector<int>> v;
    vector<int> res;
    
    void solve(vector<int> nums,int l,int h)
    {
        if(l==h)
        {
            v.push_back(nums);
            return;
        } 
        else
        {
            
        
        for(int i=l;i<=h;i++)
        {
            swap(nums[l],nums[i]);
            solve(nums,l+1,h);
           // swap(nums[l],nums[i]);
            
        }
        }
    }
    
    
    vector<vector<int>> permute(vector<int>& nums) {
        
        if(nums.size()==0)
            return v;
        v.clear();
        
        
        solve(nums,0,nums.size()-1);
        
        return v;
        
        
        
    }
};
