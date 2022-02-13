class Solution {
    private: 
     
        map<int,string> v;
        
        vector<string> ans;
public:
    
    void solve(string digits,int i,string op)
    {
        
        if(i==digits.size())
        {
            ans.push_back(op);
            return;
        } 
        
        string s=v[digits[i]-'0'];
        for(auto ch : s)
        {
            op.push_back(ch);
            solve(digits,i+1,op);
           op.pop_back();
        }
        
        
        
    }
    
    
    
    vector<string> letterCombinations(string digits) {
       
    
        
        if(digits.size()==0)
            return {};
        
        
        v[2]="abc";
        v[3]="def";
        v[4]="ghi";
        v[5]="jkl";
        v[6]="mno";
        v[7]="pqrs";
        v[8]="tuv";
        v[9]="wxyz";
            ans.clear();
       
        solve(digits,0,"");
        
        return ans;
        
    }
};
