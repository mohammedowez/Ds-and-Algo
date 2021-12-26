Example 1:

Input: s = "egg", t = "add"
Output: true

Example 2:

Input: s = "foo", t = "bar"
Output: false

Example 3:

Input: s = "paper", t = "title"
Output: true

  
  class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        if(s==t)
            return 1;
        if(s.size()!=t.size())
            return 0;
        

        map<char,int> mp1,mp2;
        for(int i=0;i<s.size();i++)
        {
            char a1=s[i];
            char a2=t[i];
            
            if(mp1[a1]!=mp2[a2])
                return 0;
            mp1[a1]=i+1;
            mp2[a2]=i+1;
        } 
        
        return 1;
    }
};
