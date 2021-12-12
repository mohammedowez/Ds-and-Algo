Example 1:

Input:
S = "aabacbebebe", K = 3
Output: 7
Explanation: "cbebebe" is the longest 
substring with K distinct characters.

Example 2:

Input: 
S = "aaaa", K = 2
Output: -1
Explanation: There's no substring with K
distinct characters.

  
  class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    int i=0,j=0;
    int n=s.size();
    int ma=0;
    
    
    
    unordered_map<char,int> mp;
    while(i<n)
    {
        
        mp[s[i]]++;
        if(mp.size()<k)
            i++;
       else if(mp.size()==k)
       {
           
           ma=max(ma,i-j+1);
           
           i++;
       } 
       else if(mp.size()>k)
       {
           
           while(mp.size()>k)
           {
               mp[s[j]]--;
               if(mp[s[j]]==0)
               {
                  mp.erase(s[j]);
               }
               j++;
           } 
           i++;
       }
        
    } 
    
    if(ma!=0)
        return ma;
    return -1;
    
    }
};
