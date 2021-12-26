Example 1:

Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: "mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, since a and b map to the same letter.

Example 2:

Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]


class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        for(auto &neword:words)
        {
            
            bool flag=true;
            map<char,int> f1;
            map<char,int> f2;
            
            for(int j=0;j<neword.size();j++)
            {
                if(f1[pattern[j]]!=f2[neword[j]])
                    flag=false;
                else 
                {
                    
                
                f1[pattern[j]]=j+1;
                f2[neword[j]]=j+1;
                }
                    
            }
            if(flag)
                res.emplace_back(neword);
            
        }
        
        return res;
        
    }
};
class Solution {
public:
   static  bool solve(string &neword,string &pattern)
    {
         bool flag=true;
           int f1[256]={0};
            int f2[256]={0};
            
            for(int j=0;j<neword.size();j++)
            {
                if(f1[pattern[j]]!=f2[neword[j]])
                   return false;
                  
                f1[pattern[j]]=j+1;
                f2[neword[j]]=j+1;
               
                    
            }
        
        return true;
    }
    
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> res;
        
        for(auto &neword:words)
        {
            if(solve(neword,pattern))
                res.emplace_back(neword);
            
        }
        
        return res;
        
    }
};
