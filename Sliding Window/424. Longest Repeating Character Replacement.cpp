Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

  
  class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
        // sliding window 
        unordered_map<char,int> mp;
        int i=0,j=0;
        int maxLen=0;
        int maxi=0;
        
        while(i<s.size())
        {
            mp[s[i]]++;
            maxi=max(maxi,mp[s[i]]);
            
            if((i-j+1)-maxi>k)
            {
                mp[s[j]]--;
                
                if(mp[s[j]]==0)
                    mp.erase(s[j]);
                j++;
            }
           
            maxLen=max(maxLen,i-j+1);
            i++;
            
        }
            
           return maxLen; 
        
    }
};
