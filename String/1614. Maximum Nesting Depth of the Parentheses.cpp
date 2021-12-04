Example 1:

Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation: Digit 8 is inside of 3 nested parentheses in the string.

Example 2:

Input: s = "(1)+((2))+(((3)))"
Output: 3

  
  class Solution {
public:
    int maxDepth(string s) {
        
        ios_base::sync_with_stdio(0),cin.tie(0);
        
        
        int c=0;
        int maxi=0;
        
        for(char i:s)
        {
            if(i=='(')
                c++;
            else if(i==')')
            {
                maxi=max(maxi,c);
                if(c>0)
                    c--;
            }
        } 
        
        return maxi;
    }
};
