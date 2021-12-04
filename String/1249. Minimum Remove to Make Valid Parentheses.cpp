Example 1:

Input: s = "lee(t(c)o)de)"
Output: "lee(t(c)o)de"
Explanation: "lee(t(co)de)" , "lee(t(c)ode)" would also be accepted.

Example 2:

Input: s = "a)b(c)d"
Output: "ab(c)d"


class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        
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
