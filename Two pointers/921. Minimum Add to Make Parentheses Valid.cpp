Example 1:

Input: s = "())"
Output: 1

Example 2:

Input: s = "((("
Output: 3

Example 3:

Input: s = "()"
Output: 0


class Solution {
public:
    int minAddToMakeValid(string s) 
    {
        if(s.empty())
            return 0;
        
        stack<char> st;
        
        for(char i:s)
        {
            if(i=='(')
                st.push(i);
            else 
            {
                if(!st.empty() && st.top()=='(')
                    st.pop();
                else 
                    st.push(i);
            } 
        } 
        return st.size();
    }
};
