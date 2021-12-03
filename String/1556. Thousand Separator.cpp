Example 1:

Input: n = 987
Output: "987"

Example 2:

Input: n = 1234
Output: "1.234"

Example 3:

Input: n = 123456789
Output: "123.456.789"


class Solution {
public:
    string thousandSeparator(int n) 
    {
        string m=to_string(n);
        if(m.size()<=3)
            return m;
        
        string s1;
        int c=0;
        for(int i=m.size()-1;i>=0;i--)
        {
            
            if(c==3)
            {
                c=0;
                s1+='.';
                
            } 
            s1+=m[i];
            c++;
        } 
        
        reverse(s1.begin(),s1.end());
        
        return s1;
    }
};
