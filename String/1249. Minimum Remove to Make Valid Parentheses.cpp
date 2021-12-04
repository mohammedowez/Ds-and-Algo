class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
       // left to right
        
        int c=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                c++;
            else if(s[i]==')')
            {
                if(c>0)
                    c--;
                else 
                    s[i]=0;
            }
        } 
        
        // right t0 left 
        c=0;
        for(int i=s.size()-1;i>=0;i--)
        {
            
            if(s[i]==')')
            {
                c++;
            } 
            else if(s[i]=='(')
            {
                if(c>0)
                    c--;
                else 
                    s[i]=0;
            }
        }
        
        string ans;
        
        for(char i:s)
        {
            if(i!=0)
                ans+=i;
        }
        
        return ans;
        
        
    }
};
