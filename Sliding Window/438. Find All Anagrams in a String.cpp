Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

  
  
  
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        


int n=s.length(), m=p.length();
	
    if(m>n)
	    return {};
	
	vector<int> pv(26,0), sv(26,0), res;
    
    for(int l=0;l<m;l++)
        pv[p[l]-'a']++;
    
    int i=0, j=0;
    
    while(j<n)
    {
        sv[s[j]-'a']++;
        
		if((j-i+1)<m)
        {            //When the current window size is smaller, just move ahead.
            j++;
        }
        
        else if((j-i+1)==m)
        {                //On hitting the window.

            if(pv==sv)
                res.push_back(i);

            sv[s[i]-'a']--;

            i++;
            j++;
        }
    }
    return res;
        
    }
};
