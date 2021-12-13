Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

  
  class Solution {
public:
    int lengthOfLongestSubstring(string s) {
     
        
        int maxLen=0;
        int i=0,j=0;
        unordered_map<char,int> mp;
        
        
        while(i<s.size())
        {
            mp[s[i]]++;
            
            if(mp.size()==i-j+1)
                maxLen=max(maxLen,i-j+1);
            
            else 
            {
                while(mp.size()<i-j+1)
                {
                    mp[s[j]]--;
                    
                    if(mp[s[j]]==0)
                        mp.erase(s[j]);
                    
                    j++;
                } 
                
            }
            i++;
        
        }
        
        return maxLen;
   // Another solution 
      
        set<char> st;
        
        int i=0,j=0;
        int maxLen=0;
        
        while(i<s.size())
        {
            
            if(st.count(s[i])==0)
            {
                st.insert(s[i]);
                maxLen=max(maxLen,i-j+1);
                i++;
            } 
            
            else
            {
                st.erase(s[j]);
                j++;
            }
            
        } 
        
        return maxLen;
        
    }
};
