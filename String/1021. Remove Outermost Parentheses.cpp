Example 1:

Input: s = "(()())(())"
Output: "()()()"
Explanation: 
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".


class Solution {
public:
    string removeOuterParentheses(string s) {
        
        stack<char> st;
        
        string ans;
        for(char i:s)
        {
            if(i=='(')
            {
                if(!st.empty())
                    ans+='(';
                
                st.push('(');
            } 
            else 
            {
                st.pop();
                if(!st.empty())
                    ans+=')';
             }
         } 
        
        return ans;
    }
};
