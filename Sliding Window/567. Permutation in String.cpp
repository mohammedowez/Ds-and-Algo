Example 1:

Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:

Input: s1 = "ab", s2 = "eidboaoo"
Output: false

  
  class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        
        int i=0,j=0;
        
        int  m=s1.size();
        int  n=s2.size();
        
        
        for(int i=0;i<m;i++)
                v1[s1[i]-'a']++;
        
        
        while(i<n)
        {
            v2[s2[i]-'a']++;
            
            if(i-j+1<m)
                i++; 
            
            else if(i-j+1==m)
            {
                if(v1==v2)
                    return true;
                else 
                {
                v2[s2[j]-'a']--;
                j++;
                i++;
                }
               
            } 
            
            
        } 
        
        return false;
        
    }
};
