Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

  
  class Solution 
{
public:
    bool wordPattern(string p, string s) 
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        
        unordered_map<char,string> mp1;
        
        unordered_map<string,char> mp2;
        
        vector<string> vs;
        stringstream ss(s);
            
         while(ss>>s)
         {
             vs.push_back(s);
         }
        
        if(p.size()!=vs.size())
            return 0;
        
        for(int i=0;i<p.size();i++)
        {
            mp1[p[i]]=vs[i];
            mp2[vs[i]]=p[i];
        }
        
        
        for(int i=0;i<vs.size();i++)
        {
            if(mp1[p[i]]!=vs[i] || mp2[vs[i]]!=p[i])
                return 0;
        }
        
        return 1;
        
    }
};
