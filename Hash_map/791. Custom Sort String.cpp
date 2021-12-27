Example 1:

Input: order = "cba", s = "abcd"
Output: "cbad"
Explanation: 
"a", "b", "c" appear in order, so the order of "a", "b", "c" should be "c", "b", and "a". 
Since "d" does not appear in order, it can be at any position in the returned string. "dcba", "cdba", "cbda" are also valid outputs.

Example 2:

Input: order = "cbafg", s = "abcd"
Output: "cbad"

  
  class Solution {
public:
    string customSortString(string order, string s) {
     
        unordered_map<char,int> mp;
        for(char i:s)
            mp[i]++;
        
        
        string op;
        
        for(int i=0;i<order.size();i++)
        {
            if(mp.find(order[i])!=mp.end())
            {
                op+=string(mp[order[i]],order[i]);
                mp.erase(order[i]);
            }
        }
        for(auto i:mp)
            op+=string(i.second,i.first);
        
        return op;
        
        
        
        
    }
};
