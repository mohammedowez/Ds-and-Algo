Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true


class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(char i:s)
        {
            if(i=='(')
                st.push(i);
            else if(i=='{')
                st.push(i);
            else if(i=='[')
                st.push(i);
            
            else 
            {
                if(!st.empty() and st.top()=='(' and i==')')
                    st.pop();
                else if(!st.empty() and st.top()=='[' and i==']')
                    st.pop();
                else if(!st.empty() and st.top()=='{' and i=='}')
                    st.pop();
                else 
                    return false;
            }
        
        }
        if(st.empty())
            return true;
        return false ;
    }
};
